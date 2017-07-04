#include"stdafx.h"
#include"Qt5Serialport.h"
#include"SerialportThead.h"
#include"CommDataHolder.h"

int commWriteData(const char *buffer, int size)
{
	return CSerialportThread::getInstance()->writeFile(buffer, size);
}

void setCommConfig(const char* com,int baudRate, char byteSize, char parity, char stopBits)
{
	CSerialportThread::getInstance()->setCommConfig(com, baudRate,byteSize,parity,stopBits);
	CSerialportThread::getInstance()->initCallBack(&CCommDataHolder::getDataCallBackS);
}

void start()
{
	CSerialportThread::getInstance()->start();
}

void end()
{
	CSerialportThread::getInstance()->end();
}

int commReadData(char* buffer, int size)
{
	return CCommDataHolder::getInstance()->getCommData(buffer, size);
}