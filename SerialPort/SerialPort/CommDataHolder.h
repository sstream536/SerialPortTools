#pragma once
#include <string>
#include <list>
#include <mutex>
using std::list;

class CCommDataHolder
{
public:
	CCommDataHolder();
	~CCommDataHolder();
	//
	static std::shared_ptr<CCommDataHolder> getInstance();
	static int getDataCallBackS(list<char> & buffer);
	
	int getCommData(char * buffer,int len);
protected:
	int getDataCallBack(list<char> & buffer);
	//
private:
	static std::shared_ptr<CCommDataHolder>  s_pInstance;
	static std::mutex s_mt;
	//
	list<char> m_listData;
	std::mutex m_mt;
};



