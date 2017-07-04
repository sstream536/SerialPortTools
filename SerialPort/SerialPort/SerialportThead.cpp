#include "StdAfx.h"
#include "SerialportThead.h"
#include<iostream>

static const int MAX_SIEZ_BUFFER_SIZE = 2048;

CSerialportThread::CSerialportThread(void)
:m_com("Com1"),m_baudRate(2400),m_byteSize(8),m_parity(NOPARITY),m_stopBits(ONESTOPBIT), m_bInit(false)
{
}

CSerialportThread::~CSerialportThread(void)
{
}

CSerialportThread * CSerialportThread::getInstance()
{
	static CSerialportThread instance_;
	return &instance_;
}

//
void CSerialportThread::setCommConfig(const char* com, int baudRate, char byteSize, char parity, char stopBits)
{
	m_com		= com;
	m_baudRate	= baudRate;
	m_byteSize	= byteSize;
	m_parity	= parity;
	m_stopBits	= stopBits;
	
}

//
void CSerialportThread::initComm()
{
	if (m_serialport.openComm(m_com) && m_serialport.setupComm(MAX_SIEZ_BUFFER_SIZE, MAX_SIEZ_BUFFER_SIZE))//设置输入输出缓冲区大小
	{
		DCB dcb;
		COMMTIMEOUTS TimeOuts;
		TimeOuts.ReadIntervalTimeout = MAXDWORD;							//读间隔超时
		TimeOuts.ReadTotalTimeoutMultiplier = 0;							//读时间系数
		TimeOuts.ReadTotalTimeoutConstant = 0;								//读时间常量
		TimeOuts.WriteTotalTimeoutMultiplier = 10;							//写时间系数
		TimeOuts.WriteTotalTimeoutConstant = 50;							//写时间常量
		if (m_serialport.setCommTimeouts(TimeOuts) && m_serialport.getCommState(dcb))
		{
			dcb.BaudRate = m_baudRate;										//波特率2400
			dcb.ByteSize = m_byteSize;										//每个字符有8位
			dcb.Parity	 = m_parity;										//无校验
			dcb.StopBits = m_stopBits;										//一个停止位
																			//
			if (m_serialport.setCommState(dcb) && m_serialport.purgeComm()) //中断读写操作并清空缓冲区
				m_bInit = true;
		}
	}
}


//
void CSerialportThread::runTask()
{
	if (!m_bInit)
	{
		initComm();
	}
	//
	while (1)
	{
		if (WaitForSingleObject(m_hEndEvent, 50) == WAIT_OBJECT_0)
			break;
		vector<char> readbuffer;
		readbuffer.resize(MAX_SIEZ_BUFFER_SIZE);
		DWORD dwRead;
		int nRet = m_serialport.readFile(readbuffer, MAX_SIEZ_BUFFER_SIZE, dwRead, NULL);
		if (nRet == -1 || nRet == 0)
			continue;
		else
		{
			list<char> tmp(readbuffer.begin(), readbuffer.begin()+dwRead);
			m_addDataCallBack(tmp);
		}
		if (WaitForSingleObject(m_hEndEvent, 50) == WAIT_OBJECT_0)
			break;
	}
	SetEvent(m_hExitEvent);
}

//
int CSerialportThread::writeFile(const char * writeBuffer, int size)
{
	DWORD ret = 0;
	vector<char> buffer;
	int nSize = strlen(writeBuffer) < size ? strlen(writeBuffer): size;
	buffer.resize(nSize);
	buffer.assign(writeBuffer, writeBuffer + nSize);
	return m_serialport.writeFile(buffer, nSize, ret, NULL);

}

//
void CSerialportThread::initCallBack(void * pCallBack)
{
	m_addDataCallBack = (pGET_DATA_CAAL_BACK)pCallBack;
}
