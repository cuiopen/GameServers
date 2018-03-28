#include "HttpLogic.h"
#include "CSVDataInfo.h"
#include "HttpEvent.h"
#include "LibEvent.h"
#include "Common.h"
#include "ClientSocket.h"
#include "LoginInfo.h"
#include "aes.h"


int HttpLogic::SERVER_PORT=0;
string HttpLogic::SERVER_CODE="";
HttpLogic *HttpLogic::m_Ins = NULL;



void HttpLogic::aes_decrypt(char* in, int inlen, char* out)
{
	if (!in || !out) return;
	unsigned char *iv = new unsigned char[AES_BLOCK_SIZE];
	memcpy(iv, DECKEY, AES_BLOCK_SIZE);

	AES_KEY aes;
	if (AES_set_encrypt_key((unsigned char*)DECKEY, 128, &aes) < 0)
	{
		return;
	}

	int num = 0;
	AES_cfb128_encrypt((unsigned char*)in, (unsigned char*)out, inlen, &aes, iv, &num, AES_DECRYPT);
	inlen = inlen / AES_BLOCK_SIZE*AES_BLOCK_SIZE;
	out[inlen + num] = '\0';

}

void HttpLogic::aes_encrypt(char* in, int inlen, char* out)
{
	if (!in || !out) return;
	unsigned char *iv = new unsigned char[AES_BLOCK_SIZE];
	memcpy(iv, DECKEY, AES_BLOCK_SIZE);
	AES_KEY aes;
	if (AES_set_encrypt_key((unsigned char*)DECKEY, 128, &aes) < 0)
	{
		return;
	}
	int num = 0;
	AES_cfb128_encrypt((unsigned char*)in, (unsigned char*)out, inlen, &aes, iv, &num, AES_ENCRYPT);
	inlen = inlen / AES_BLOCK_SIZE*AES_BLOCK_SIZE;
	out[inlen + num] = '\0';

}



HttpLogic::HttpLogic(){
	//this->scheduleUpdate(0.5, 1.0);
}
HttpLogic::~HttpLogic(){
	
}

bool HttpLogic::init()
{
	
    return true;
}

HttpLogic *HttpLogic::getIns(){
	if (!m_Ins){
		m_Ins = new HttpLogic();
		m_Ins->init();
	}
	return m_Ins;
}

void HttpLogic::update(float dt){
	printf("httplogic-update\n");
}

void HttpLogic::respondleLogic(YMSocketData sd){
	int cmd = sd["cmd"].asInt();
	if (cmd == 0x0B){
		GateDataCall(sd);
	}
	else if (cmd == 0x0A){
		ManagerDataCall(sd);
	}
	else if (cmd == 0x0C){
		DBDataCall(sd);
	}
	else if (cmd == 0x10){
		RegisterCall(sd);
	}
}

void HttpLogic::HandleLogic(YMSocketData sd, char *&buff, int &sz){
	printf("socketdata:%s", sd.getJsonString().c_str());
}

void HttpLogic::requestGateData(){
	string url=sqlhttp;
	YMSocketData sd;
	sd["cmd"] = 0x0B;
	sd["type"] = 1;
	HttpEvent::getIns()->requestData(url,sd);
}

void HttpLogic::GateDataCall(YMSocketData sd){
	int err = sd["err"].asInt();
	if (err == 0){
		SERVER_PORT = sd["serverport"].asInt();
		printf("\n/************************************************/\n");
		std::cout << "socket start:" <<SERVER_PORT<< std::endl;
		printf("/************************************************/\n");
		LibEvent *clib = LibEvent::getIns();
		clib->StartServer(SERVER_PORT, 2, 5000, 600, 600);
		getchar();
		clib->StopServer();
	}
	else{
		printf("未获取到数据\n");
	}
}

void HttpLogic::requestManagerData(){
	string url = sqlhttp;
	YMSocketData sd;
	sd["cmd"] = 0x0A;
	sd["type"] = 1;
	HttpEvent::getIns()->requestData(url,sd);
}

DWORD WINAPI threadClient(int lPVOID){
	HttpLogic *p = HttpLogic::getIns();
	ClientSocket::getIns()->connect(p->m_logicmnip.c_str(),p->m_logicmnport);
	return GetCurrentThreadId();
}

void HttpLogic::ManagerDataCall(YMSocketData sd){
	int err = sd["err"].asInt();
	if (err == 0){
		m_logicmnip = sd["serverip"].asString();
		m_logicmnport = sd["serverport"].asInt();
		m_servername = sd["servername"].asString();
		printf("\n/************************************************/\n");
		std::cout << "client socket start:ip:" << m_logicmnip.c_str() << " port:" << m_logicmnport << std::endl;
		printf("/************************************************/\n");
		thread t1(&threadClient, NULL);
		t1.detach();
	}
	else{
		printf("未获取到数据\n");
	}
}

void HttpLogic::requestDBData(string uid, string pwd){
	string url = sqlhttp;
	YMSocketData sd;
	sd["cmd"] = 0x0C;
	sd["userid"] = uid;
	sd["pwd"] = pwd;
	
	HttpEvent::getIns()->requestData(url,sd);
}

void HttpLogic::DBDataCall(YMSocketData sd){
	string uid = sd["data"]["userid"].asString();
	string pwd = sd["data"]["pwd"].asString();
	string seesion = uid+pwd+LOGIC_TOKEN;
	MD5 md5;
	md5.update(seesion);
	ClientData *data = LibEvent::getIns()->getClientData(md5.toString());
	if (data&&data->_conn){
		LoginInfo::getIns()->SendSLogin(sd, data->_conn->fd);
	}
}

void HttpLogic::requestRegister(YMSocketData &sd){
	string url = sqlhttp;
	sd["cmd"] = 0x10;
	
	HttpEvent::getIns()->requestData(url,sd);
}

void HttpLogic::RegisterCall(YMSocketData sd){
	printf("Register sd:%s\n",sd.getJsonString().c_str());
	string uid = sd["data"]["userid"].asString();
	string pwd = sd["data"]["pwd"].asString();
	string seesion = uid + pwd + LOGIC_TOKEN;
	MD5 md5;
	md5.update(seesion);
	ClientData *data = LibEvent::getIns()->getClientData(md5.toString());
	if (data&&data->_conn){
		LoginInfo::getIns()->SendSRegister(sd, data->_conn->fd);
	}
}