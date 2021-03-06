﻿#ifndef __LYNX_GAME_SERVER_ConfigData_H__
#define __LYNX_GAME_SERVER_ConfigData_H__
#include "stdafx.h"

using namespace std;

#define CARDNUMBER 120

enum HuTypeEnum
{
	None=0,
	PI,//屁胡
	PENGPENG,//碰碰胡
	QIDUI,//七对
	QINGYISE,//清一色
	QYSPENG,//清一色碰碰胡
	QYSQD,//清一色七对
};

enum HeiOrYing
{
	RUAN=0,
	HEI,
};

enum HUTYPE{
	ZIMO_TYPE,//自摸
	PAO_TYPE,//放炮
	PAOGANG_TYPE,//抢杠
	ZIMOGANG_TYPE//杠上开花
};

enum OTHERHANDPAO{
	MENQING_PAO,//门清
	KA_DU_PAO,//卡独
	GANGHU_PAO,//杠胡
	HONGBAN_PAO,//红中白板
	KE_PAO,//除去红中白板
};

enum PENGPAO{
	NONE_PAO,
	MGANG_PAO,
	AGANG_PAO,
	PENG_PAO,
};

struct HuItem
{
	HuTypeEnum	_hutype;
	HeiOrYing	_hy;
};

struct PaoItem
{
	map<HUTYPE,int> _hu;
	map<OTHERHANDPAO, int> _handpao;
	map<PENGPAO, int> _pengpao;
	int _fapao;
};

static char g_all_mjkind[] = {
	0x01 + '0', 0x02 + '0', 0x03 + '0', 0x04 + '0', 0x05 + '0', 0x06 + '0', 0x07 + '0', 0x08 + '0', 0x09 + '0',
	0x11 + '0', 0x12 + '0', 0x13 + '0', 0x14 + '0', 0x15 + '0', 0x16 + '0', 0x17 + '0', 0x18 + '0', 0x19 + '0',
	0x21 + '0', 0x22 + '0', 0x23 + '0', 0x24 + '0', 0x25 + '0', 0x26 + '0', 0x27 + '0', 0x28 + '0', 0x29 + '0',
	0x31 + '0', 0x32 + '0', 0x33 + '0', 0x34 + '0',
	0x41 + '0', 0x42 + '0', 0x43 + '0'
};

#define g_kind (sizeof(g_all_mjkind)/sizeof(int))

static char g_all_mj[] = {
	g_all_mjkind[0], g_all_mjkind[0], g_all_mjkind[0], g_all_mjkind[0],
	g_all_mjkind[1], g_all_mjkind[1], g_all_mjkind[1], g_all_mjkind[1],
	g_all_mjkind[2], g_all_mjkind[2], g_all_mjkind[2], g_all_mjkind[2],
	g_all_mjkind[3], g_all_mjkind[3], g_all_mjkind[3], g_all_mjkind[3],
	g_all_mjkind[4], g_all_mjkind[4], g_all_mjkind[4], g_all_mjkind[4],
	g_all_mjkind[5], g_all_mjkind[5], g_all_mjkind[5], g_all_mjkind[5],
	g_all_mjkind[6], g_all_mjkind[6], g_all_mjkind[6], g_all_mjkind[6],
	g_all_mjkind[7], g_all_mjkind[7], g_all_mjkind[7], g_all_mjkind[7],
	g_all_mjkind[8], g_all_mjkind[8], g_all_mjkind[8], g_all_mjkind[8],

	g_all_mjkind[9], g_all_mjkind[9], g_all_mjkind[9], g_all_mjkind[9],
	g_all_mjkind[10], g_all_mjkind[10], g_all_mjkind[10], g_all_mjkind[10],
	g_all_mjkind[11], g_all_mjkind[11], g_all_mjkind[11], g_all_mjkind[11],
	g_all_mjkind[12], g_all_mjkind[12], g_all_mjkind[12], g_all_mjkind[12],
	g_all_mjkind[13], g_all_mjkind[13], g_all_mjkind[13], g_all_mjkind[13],
	g_all_mjkind[14], g_all_mjkind[14], g_all_mjkind[14], g_all_mjkind[14],
	g_all_mjkind[15], g_all_mjkind[15], g_all_mjkind[15], g_all_mjkind[15],
	g_all_mjkind[16], g_all_mjkind[16], g_all_mjkind[16], g_all_mjkind[16],
	g_all_mjkind[17], g_all_mjkind[17], g_all_mjkind[17], g_all_mjkind[17],

	g_all_mjkind[18], g_all_mjkind[18], g_all_mjkind[18], g_all_mjkind[18],
	g_all_mjkind[19], g_all_mjkind[19], g_all_mjkind[19], g_all_mjkind[19],
	g_all_mjkind[20], g_all_mjkind[20], g_all_mjkind[20], g_all_mjkind[20],
	g_all_mjkind[21], g_all_mjkind[21], g_all_mjkind[21], g_all_mjkind[21],
	g_all_mjkind[22], g_all_mjkind[22], g_all_mjkind[22], g_all_mjkind[22],
	g_all_mjkind[23], g_all_mjkind[23], g_all_mjkind[23], g_all_mjkind[23],
	g_all_mjkind[24], g_all_mjkind[24], g_all_mjkind[24], g_all_mjkind[24],
	g_all_mjkind[25], g_all_mjkind[25], g_all_mjkind[25], g_all_mjkind[25],
	g_all_mjkind[26], g_all_mjkind[26], g_all_mjkind[26], g_all_mjkind[26],

	g_all_mjkind[27], g_all_mjkind[27], g_all_mjkind[27], g_all_mjkind[27],
	g_all_mjkind[28], g_all_mjkind[28], g_all_mjkind[28], g_all_mjkind[28],
	g_all_mjkind[29], g_all_mjkind[29], g_all_mjkind[29], g_all_mjkind[29],
	g_all_mjkind[30], g_all_mjkind[30], g_all_mjkind[30], g_all_mjkind[30],
	
	g_all_mjkind[31], g_all_mjkind[31], g_all_mjkind[31], g_all_mjkind[31],
	g_all_mjkind[32], g_all_mjkind[32], g_all_mjkind[32], g_all_mjkind[32],
	g_all_mjkind[33], g_all_mjkind[33], g_all_mjkind[33], g_all_mjkind[33],
};

struct PaoNeed
{
	PaoNeed(){
		memset(_handcards,0,sizeof(int)*14);
		memset(_peng, 0, sizeof(int)* 4);
		memset(_ptype, 0, sizeof(PENGPAO)* 4);
		_facount = 0;
		_bao = 0;
		_baoniang = 0;
		_zhua = false;
		_isgang = false;
		_hu._hutype = None;
		_hu._hy = RUAN;
		_hucard = 0;
	}
	char _handcards[14];
	char _peng[4];
	PENGPAO _ptype[4];
	int _facount;
	char _bao;
	char _baoniang;
	bool _zhua;
	bool _isgang;
	HuItem _hu;
	int _hucard;
};

class ConfigData 
{
public:
	ConfigData();
	virtual ~ConfigData();
	static ConfigData *getIns();
	void init();
	void quickSort(int *s, int l, int r);
	int getMJ();
	int getMJ(int index);
	void initMJ();
	void test();
	PaoNeed isHu(int *pai, bool isqing, int baovalue);
	PaoNeed isHu(char *pai, bool isqing, char baovalue);
	void isHu(char *pai, bool isqing,int &index,string &hcon);
	PaoNeed isHu(char* pai,int index, bool isqing);
private:
	void createHus();
	bool PushHus(string &content, int index, map<int, set<string>> &zjallmaps);
	bool PushHus1(string &content, int index, string &zjallmaps1, map<int, string> &mmaps);
	void PushHus2(string &content, int index, map<int, string> &maps);
	bool Over4(string &content);
	bool OverLen(string &content, int count);
	void eraseEmpty(string &content,string old);
	string inserDui(string &content, char va);
	void addnumber(string &content, int num);
	void Compress(string &content);
	void getHusString(int index,string &content);
	void getBaoHusString(int index,int len,string &content);
	bool isHaveFile(int index);
private:
	static ConfigData *m_ins;
	vector<char> m_cards;
	int m_index;
	map<int, int> m_husindex;
};


#endif // __LYNX_GAME_SERVER_ConfigData_H__