#pragma once
#include <Windows.h>
#include <string>
#include <vector>
using std::vector;
using std::string;
class CSerialport
{
public:
	CSerialport();
	~CSerialport();
	BOOL openComm(const string & name);
	BOOL closeComm();
	BOOL setCommState(const DCB & dcb)const;
	BOOL getCommState(DCB & dcb)const;
	BOOL setCommTimeouts(const COMMTIMEOUTS & commtimeOuts)const;
	BOOL purgeComm(DWORD flags = PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT)const;
	BOOL setupComm(DWORD dwInQueue, DWORD dwOutQueue)const;
	int  readFile(vector<char> & buffer, DWORD nNumberOfBytesToRead,DWORD & lpNumberOfBytesRead, LPOVERLAPPED pLoverlapped = NULL);
	int  writeFile(vector<char> & buffer, DWORD nNumberOfBytesToRead, DWORD & lpNumberOfBytesRead, LPOVERLAPPED pLoverlapped = NULL);
	string getPortName()const;
	HANDLE getHandle()const;
	//
private:
	HANDLE m_hspCom;
	string m_commName;
};

