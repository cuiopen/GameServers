#include "HttpLogic.h"
#include "SqlControl.h"
#include "DataBaseUserInfo.h"
#include "aes.h"
#define DECKEY "FQ6M1w0GswdKkTuZWcFmM1rU3bDB/CTiw+KrONdCPOg"



HttpLogic *HttpLogic::m_Ins = NULL;


int HttpLogic::aes_decrypt(char* in, int inlen,char* key, char* out)
{
	if (!in || !key || !out) return 0;
	unsigned char *iv = new unsigned char[AES_BLOCK_SIZE];
	memcpy(iv, key, AES_BLOCK_SIZE);

	AES_KEY aes;
	if (AES_set_encrypt_key((unsigned char*)key, 128, &aes) < 0)
	{
		return 0;
	}
	
	int num = 0,en_len=0;
	AES_cfb128_encrypt((unsigned char*)in, (unsigned char*)out, inlen, &aes, iv, &num, AES_DECRYPT);
	
	return num;

}

int HttpLogic::aes_encrypt(char* in, int inlen, char* key, char* out)
{
	if (!in || !key || !out) return 0;
	unsigned char *iv = new unsigned char[AES_BLOCK_SIZE];
	memcpy(iv, key, AES_BLOCK_SIZE);
	AES_KEY aes;
	if (AES_set_encrypt_key((unsigned char*)key, 128, &aes) < 0)
	{
		return 0;
	}
	
	int num = 0,en_len=0;
	AES_cfb128_encrypt((unsigned char*)in, (unsigned char*)out, inlen, &aes, iv, &num, AES_ENCRYPT);
	
	return num;

}



HttpLogic::HttpLogic(){
	m_pSQLInfo = new SQLInfo();

	
}
HttpLogic::~HttpLogic(){
	delete m_pSQLInfo;
	m_pSQLInfo = NULL;
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

void HttpLogic::HandleLogic(YMSocketData sd, char *&buff, int &sz){
	int cmd = sd["cmd"].asInt();
	if (cmd == 0x01){
		SqlStart(sd,buff,sz);
	}
	else if (cmd==0x02){
		SqlClose(buff,sz);
	}
	else if (cmd == 0x03){
		SqlExcute(sd, buff, sz);
	}
	else if (cmd == 0x04){
		SelectDB(sd["dbname"].asString(), buff, sz);
	}
	else if (cmd == 0x05){
		SelectTableData(sd["tname"].asString(), buff, sz);
	}
	else if (cmd == 0x06){
		SqlConnect( buff, sz);
	}
	else if (cmd == 0x07){
		SqlColumns(sd["tname"].asString(),buff, sz);
	}
	else if (cmd == 0x08){
		SqlFind(sd, buff, sz);
	}
}

void HttpLogic::SqlConnect(char *&buff, int &sz){
	YMSocketData sd1;
	sd1["err"] = SqlControl::getIns()->isConnect();
	sd1.serializer(buff, &sz);
}

void HttpLogic::SqlStart(YMSocketData sd, char *&buff, int &sz){
	printf("%s\n",sd.getJsonString().c_str());
	m_pSQLInfo->_ip = sd["ip"].asString();
	m_pSQLInfo->_name = sd["name"].asString();
	m_pSQLInfo->_pass = sd["pass"].asString();
	m_pSQLInfo->_db = sd["db"].asString();
	m_pSQLInfo->_port = sd["port"].asInt();
	bool ist= SqlControl::getIns()->start();

	YMSocketData sd1;
	if (ist){
		sd1["err"] = 0;
		SQLInfo *p = HttpLogic::getIns()->getSQLInfo();
		sd1["dbname"] = p->_db;

		vector<string> dbs = DataBaseUserInfo::getIns()->getDatabases();
		for (int i = 0; i < dbs.size(); i++){
			sd1["dbs"][i] = dbs[i];
		}

		vector<string> tables = DataBaseUserInfo::getIns()->getdbtables();
		for (int i = 0; i < tables.size(); i++){
			sd1["tables"][i] = tables[i];
		}
	}
	else{
		sd1["err"] = 1;
	}
	sd1.serializer(buff, &sz);
}

void HttpLogic::SqlClose(char *&buff, int &sz){
	bool ist= SqlControl::getIns()->close();
	YMSocketData sd1;
	if (ist){
		sd1["err"] = 0;
	}
	else{
		sd1["err"] = 1;
	}
	sd1.serializer(buff, &sz);
}

void HttpLogic::SelectDB(string dbname, char *&buff, int &sz){
	bool ist= SqlControl::getIns()->SelectDB(dbname);
	YMSocketData sd;
	if (ist){
		sd["err"] = 0;
		sd["dbname"] = dbname;
		vector<string> tables = SqlControl::getIns()->getAllTables();
		for (int i = 0; i < tables.size(); i++){
			sd["tables"][i] = tables[i];
		}
	}
	else{
		sd["err"] = 1;
	}
	sd.serializer(buff, &sz);
}

void HttpLogic::SelectTableData(string tname, char *&buff, int &sz){
	YMSocketData sd;
	sd["err"] = 0;
	sd["tname"] = tname;
	DataBaseUserInfo *p = DataBaseUserInfo::getIns();
	
	std::map<string, ::google::protobuf::Message*> dbusers = p->getDBDatas(tname);
	std::map<string, ::google::protobuf::Message*>::iterator itr = dbusers.begin();
	int i = 0;
	for (itr; itr != dbusers.end(); itr++){
		if (tname.compare(MJ_TABLENAME_USER) == 0){
			DBUserInfo msg;
			msg.CopyFrom(*itr->second);
			p->setDBUserToSocketData(msg, sd, "datas", i);
		}
		else if (tname.compare(MJ_TABLENAME_RECORDS) == 0){

		}
		else if (tname.compare(MJ_TABLENAME_DETAIL_RECORDS) == 0){

		}
		i++;
	}
	
	
	sd.serializer(buff, &sz);
}

void HttpLogic::SqlColumns(string tname, char *&buff, int &sz){
	YMSocketData sd;
	sd["err"] = 0;
	sd["tname"] = tname;
	
	
	vector<string>vec = DataBaseUserInfo::getIns()->getTableColumnName(tname);
	for (int i = 0; i < vec.size(); i++){
		sd["columns"][i] = vec.at(i);
	}
	sd.serializer(buff, &sz);
}

void HttpLogic::SqlFind(YMSocketData sd, char *&buff, int &sz){
	string tname = sd["tname"].asString();
	string coname = sd["coname"].asString();
	string covalue = sd["covalue"].asString();
	YMSocketData sd1;
	sd1["tname"] = tname;
	DataBaseUserInfo *p = DataBaseUserInfo::getIns();
	sd1["prikey"] = p->getTablePrikey(tname);
	if (tname.compare(MJ_TABLENAME_USER) == 0){
		string prikey;
		DBUserInfo user;
		vector<::google::protobuf::Message*> vec = p->getDBData(tname, coname, covalue);
		if (!vec.empty()){
			user.CopyFrom(*vec.at(0));
			if (user.userid().empty()){
				sd1["err"] = 1;
			}
			else{
				sd1["err"] = 0;
				p->setDBUserToSocketData(user, sd1);
			}
		}
		else{
			sd1["err"] = 1;
		}
	}
	else if (tname.compare(MJ_TABLENAME_RECORDS) == 0){

	}
	else if (tname.compare(MJ_TABLENAME_DETAIL_RECORDS) == 0){

	}
	sd1.serializer(buff, &sz);
}

void HttpLogic::SqlExcute(YMSocketData sd, char *&buff, int &sz){
	string tname = sd["tname"].asString();
	string key = sd["key"].asString();
	string keyvalue = sd["keyvalue"].asString();
	printf("%s",sd.getJsonString().c_str());
	int err = 0;
	if (tname.compare(MJ_TABLENAME_USER) == 0){
		map<string, string>maps;
		for (int i = 0; i < 12; i++){
			string coname = DataBaseUserInfo::g_dbitennames[i];
			if (sd.isMember(coname)){
				string covalue= sd[coname].asString();
				maps.insert(make_pair(coname,covalue));
			}
		}
		err=DataBaseUserInfo::getIns()->updateDBDataByKey(tname,maps, key, keyvalue);
	}
	else if (tname.compare(MJ_TABLENAME_RECORDS) == 0){

	}
	else if (tname.compare(MJ_TABLENAME_DETAIL_RECORDS) == 0){

	}
	YMSocketData sd1;
	sd1["err"] = err;
	sd1["tname"] = tname;
	sd1.serializer(buff, &sz);
}

string HttpLogic::encryptStringFromProto(::google::protobuf::Message* msg){
	int sz = msg->ByteSize();
	string sm;
	msg->SerializePartialToString(&sm);
	char *out = new char[4096];
	int num=aes_encrypt((char *)sm.c_str(), sz, DECKEY, out);
	out[sz] = '\0';
	string ss = out;
	int len = ss.length();
	delete out;
	return ss;
}

void HttpLogic::decryptStringFromProto(string keyvalue, int sz, ::google::protobuf::Message* msg){
	int len = keyvalue.length();
	char out[4096];
	int nn = aes_decrypt((char *)keyvalue.c_str(), len, DECKEY, out);
	out[sz + nn] = '\0';
	msg->ParsePartialFromArray(out, sz);
}

string HttpLogic::encryptStringFromString(string in,int sz){
	char *out = new char[4096];
	int num = aes_encrypt((char *)in.c_str(), sz, DECKEY, out);
	out[sz+num] = '\0';
	string ss = out;
	int len = ss.length();
	delete out;
	return ss;
}

string HttpLogic::decryptStringFromString(string in,int sz){
	char *out = new char[4096];
	int nn = aes_decrypt((char *)in.c_str(), sz, DECKEY, out);
	out[sz + nn] = '\0';
	string ss = out;
	int len = ss.length();
	delete out;
	return ss;
}