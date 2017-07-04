#include "stdafx.h"
#include "Serialport.h"
#include "Ecoder.h"


CSerialport::CSerialport()
	:m_hspCom(INVALID_HANDLE_VALUE), m_commName("")
{
}


CSerialport::~CSerialport()
{
	if (m_hspCom != INVALID_HANDLE_VALUE)
		CloseHandle(m_hspCom);
	m_hspCom = INVALID_HANDLE_VALUE;
}

BOOL CSerialport::openComm(const string & name)
{
	wstring wname;
	if (!name.empty())
		CEcoder::ansiToUnicode(name, wname);
	else
		return TRUE;
	m_hspCom = CreateFile(wname.c_str(), GENERIC_READ | GENERIC_WRITE,0
						, NULL, OPEN_EXISTING,0,                         //ILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED
						  NULL);
	if (m_hspCom == INVALID_HANDLE_VALUE)
	{
		DWORD error = GetLastError();
		return FALSE;
	}
	m_commName = name;
	return TRUE;
}


BOOL CSerialport::closeComm()
{
	if (m_hspCom != INVALID_HANDLE_VALUE)
		CloseHandle(m_hspCom);
	m_hspCom = INVALID_HANDLE_VALUE;
	return TRUE;
}


BOOL CSerialport::setCommState(const DCB & dcb)const
{
	DCB tmp = dcb;
	return SetCommState(m_hspCom,&tmp);
}

BOOL CSerialport::getCommState(DCB & dcb)const
{
	return GetCommState(m_hspCom,&dcb);
}

BOOL CSerialport::setCommTimeouts(const COMMTIMEOUTS & commtimeOuts)const
{
	COMMTIMEOUTS tmp = commtimeOuts;
	return SetCommTimeouts(m_hspCom,&tmp);
}

BOOL CSerialport::purgeComm(DWORD flags)const
{
	return PurgeComm(m_hspCom,flags);
	//在读写串口之前，还要用PurgeComm()函数清空缓冲区
	//PURGE_TXABORT	  中断所有写操作并立即返回，即使写操作还没有完成。
	//PURGE_RXABORT	  中断所有读操作并立即返回，即使读操作还没有完成。
	//PURGE_TXCLEAR	  清除输出缓冲区
	//PURGE_RXCLEAR	  清除输入缓冲区
}

BOOL CSerialport::setupComm(DWORD dwInQueue, DWORD dwOutQueue)const
{
	return SetupComm(m_hspCom, dwInQueue, dwOutQueue);
}

string CSerialport::getPortName()const
{
	return m_commName;
}

HANDLE CSerialport::getHandle()const
{
	return m_hspCom;
}

int CSerialport::readFile(vector<char> & buffer, DWORD nNumberOfBytesToRead, DWORD & lpNumberOfBytesRead, LPOVERLAPPED pLoverlapped)
{
	return ReadFile(m_hspCom,&buffer[0], nNumberOfBytesToRead, &lpNumberOfBytesRead, pLoverlapped) == TRUE ? lpNumberOfBytesRead:-1;
}

int CSerialport::writeFile(vector<char> & buffer, DWORD nNumberOfBytesToRead, DWORD & lpNumberOfBytesRead, LPOVERLAPPED pLoverlapped)
{
	return WriteFile(m_hspCom, &buffer[0], nNumberOfBytesToRead, &lpNumberOfBytesRead, pLoverlapped) == TRUE ? lpNumberOfBytesRead : -1;
}