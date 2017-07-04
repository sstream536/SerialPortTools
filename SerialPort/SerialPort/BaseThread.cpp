#include "StdAfx.h"
#include "BaseThread.h"
#include <process.h>

CBaseThread::CBaseThread(void)
:	m_hThreadHandle(NULL),
    m_hExitEvent(NULL),
	m_hEndEvent(NULL),
	m_uThreadID(-1)
{
}

CBaseThread::~CBaseThread(void)
{
}

void CBaseThread::start()
{
	m_hEndEvent  = CreateEvent(NULL,TRUE,FALSE,NULL);
	m_hExitEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	//
	if (!m_hThreadHandle)
	{
		m_hThreadHandle = (HANDLE)_beginthreadex(
			NULL,0,&CBaseThread::threadFunc,(void*)this,0,&m_uThreadID);
	}
	if (NULL == m_hThreadHandle)
	{
		m_uThreadID = -1;
	}
}

//
void CBaseThread::end()
{
	SetEvent(m_hEndEvent);
	WaitForSingleObject(m_hExitEvent,INFINITE);
	//
	if(m_hEndEvent != NULL) 
	{
		CloseHandle(m_hEndEvent);
		m_hEndEvent = NULL;
	}
	if(m_hExitEvent != NULL)
	{
		CloseHandle(m_hExitEvent);
		m_hExitEvent = NULL;
	}
	if(m_hThreadHandle != NULL) 
	{
		CloseHandle(m_hThreadHandle);
		m_hThreadHandle = NULL;
	}
}

void CBaseThread::resume()
{
	if (m_hThreadHandle != NULL)
	{
		ResumeThread(m_hThreadHandle);
	}
}

void CBaseThread::suspend()
{
	if (m_hThreadHandle != NULL)
	{
		SuspendThread(m_hThreadHandle);
	}
}

BOOL CBaseThread::isRun() const
{
	return (NULL == m_hThreadHandle);
}

BOOL CBaseThread::getThreadID() const
{
	return m_uThreadID;
}
//
unsigned CBaseThread::threadFunc(void* pParam)
{
	CBaseThread * pBaseThread = (CBaseThread*)pParam;
	pBaseThread->runTask();
	//
	//_endthreadex(0);
	return 0; //_endthreadex自动调用
}

			