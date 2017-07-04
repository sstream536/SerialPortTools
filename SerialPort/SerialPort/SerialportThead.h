#pragma once
#include"BaseThread.h"
#include"Serialport.h"
#include<vector>
#include<list>
#include<mutex>
using std::vector;
using std::list;

typedef int (*pGET_DATA_CAAL_BACK)(list<char> &);

class CSerialportThread :
	public CBaseThread
{
public:
	
	CSerialportThread(void);
	virtual ~CSerialportThread(void);
	void setCommConfig(const char* com, int baudRate, char byteSize, char parity, char stopBits);
	static CSerialportThread * getInstance();
	int  writeFile(const char * writeBuffer,int size);
	void initCallBack(void *);
protected:
	virtual void runTask();
	void initComm();
protected:
	CSerialport m_serialport;
	//
	string m_com;
	int m_baudRate;
	char m_byteSize;
	char m_parity;
	char m_stopBits;
	bool m_bInit;
	pGET_DATA_CAAL_BACK m_addDataCallBack;
};
