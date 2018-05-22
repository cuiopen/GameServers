﻿#ifndef __LYNX_GAME_SERVER_RedisGet_H__
#define __LYNX_GAME_SERVER_RedisGet_H__
#include "stdafx.h"
#include "Common.h"
using namespace std;

struct SignStatus
{
	SignStatus(){
		_signcount = 0;
		_issign = false;
		_left = 1;
		_time = Common::getLocalTimeDay1();
	}
	string _uid;
	int _signcount;
	bool _issign;
	int _left;
	string _time;//日期
};

struct FirstBuyItem :public Object
{
	int _sid;
	vector<int> _rid;
	int _conid;
	vector<int> _giveid;
};

struct PExchangeCode :public Object
{
	int _id;
	vector<int> _rewardid;
	string _code;
	bool _isdui;
};

typedef map<string, UserBase *> UserBaseMap;
typedef map<string, map<string,Friend *>> FriendMap;

class RedisGet 
{
public:
	RedisGet();
	virtual ~RedisGet();
	
	static RedisGet *getIns();
	void init();

	bool SelectDB(REDISTYPE type);
	int getRedisDBIndex(string name);

	map<string, SConfig *> getSConfig();
	SConfig *getSConfig(string uid);
	void setSConfig(string uid, SConfig *sc);

	string getPass(string uid);
	map<string, string> getPass();
	void setPass(string uid,string pass);

	string getOpenidPass(string openid);
	UserBaseMap getUserBases();
	UserBase *getUserBase(string uid);
	void setUserBase(UserBase *ub);

	void setUserLoginTime(string uid,time_t t);
	time_t getUserLoginTime(string uid);
	map<string, time_t> getUserLoginTimes();

	map<string, string> getOpenids();

	map<int, vector<Rank *>> getRanks();
	vector<Rank *>getRank(int type);

	map<int, ShopItem*> getShop();
	ShopItem *getShop(int shopid);
	FirstBuyItem *getFirstBuy();

	map<string, map<int, Mail *>>getMails();
	map<int, Mail *> getMail(string uid);
	Mail *getMail(string uid, int eid);
	
	FriendMap getFriend();
	map<string, Friend *> getFriend(string uid);
	Friend *getFriend(string uid, string fuid);
	void setFriend(string uid,string fuid,bool isadd);

	map<string, map<int, FriendNotice *>> getFriendNotices();
	void setFriendNotice(string uid,FriendNotice *p);
	void eraseFriendNotice(string uid, FriendNotice *p);
	map<int, FriendNotice *> getFriendNotice(string uid);
	FriendNotice *getFriendNotice(string uid,string fuid);
	FriendNotice *getFriendNotice(string uid, int nid);

	map<int, Active *> getActive(int type);
	map<int, map<int, Active *>> getActives();

	map<int, Task *> getTask();
	Task *getTask(int tid);
	Status *getTaskStatus(string uid, int taskid);//需要删除
	map<string, map<int, Status *>> getTaskStatus();
	map<int, Status *> getTaskStatus(string uid);

	map<int, ExAward *> getExAward();
	ExAward *getExAward(int id);

	map<int,Reward *> getReward();
	Reward *getReward(int rid);
	vector<ExRecord> getExRecord(string uid);
	void PushExRecord(string uid,ExRecord p);

	int setExRecordStatus(string uid, int rid);
	vector<SignAward> getSignAward();
	SignStatus *getSignStatus(string uid);
	void setSignStatus(SignStatus *ss);//不写入数据库
	map<string, SignStatus *> getSignStatuss();

	vector<SignZhuan> getSignZhuan();
	map<int,Prop > getProp();
	Prop getProp(int id);
	vector<Task > getFree();

	
	int MailID();
	
	string getExchangeCode();
	int getExchangeRecordId(string uid);

	map<string, PExchangeCode*> getCSVExchangeCode();
	PExchangeCode* getPExchangeCode(string code);

	vector<bool> getExcode();
	bool getExcode(string code);
	void setEXCodeStatus(int id, bool ist);//不记录到数据库中
private:
	map<int, FriendNotice *> getFriendNoticeB(string uid);
private:
	static RedisGet *m_ins;
	redis *m_redis;
	map<int, Prop > m_pProps;
	map<int, Reward> m_pRewards;
	map<int,ShopItem*> m_pShopItems;
	map<int,Task> m_tasks;
	map<string, map<int, Status *>> m_taskstatus;
	vector<SignZhuan> m_pSignZhuans;
	vector<SignAward> m_pSignAwards;
	map<int,ExAward *> m_pExAwards;
	map<int, map<int, Active *>> m_pActives;
	vector<Task> m_pFrees;

	map<int, vector<Rank *>> m_pRanks;
	map<string, map<int, Mail *>> m_pMails;

	map<string, SConfig *>m_pSConfigs;
	FirstBuyItem *m_pFirstBuyItem;
	map<string, PExchangeCode*> m_pExchangeCodes;
	vector<bool> m_pEXCodes;
	map<string, vector<ExRecord>> m_pExRecords;
	map<string, SignStatus*>m_pSignStatuss;
	
	FriendMap m_pfriends;
	UserBaseMap m_pUserBases;
	
	map<string, time_t> m_pUserLoginTime;
	map<string, string>m_pPass;
	map<string, string>m_pOpenids;
	map<string, map<int,FriendNotice *>>m_pFriendNotices;

	map<string, REDISDBName *>m_RedisDBNames;
};


#endif // __LYNX_GAME_SERVER_RedisGet_H__