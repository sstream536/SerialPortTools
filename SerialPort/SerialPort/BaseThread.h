#pragma once
#include <Windows.h>

class CBaseThread
{
public:
	CBaseThread(void);
	virtual ~CBaseThread(void);
public:
	virtual void start();										//创建线程
	virtual void end();											//结束线程
	virtual void resume();										//重启线程
	virtual void suspend();										//暂停线程
	//
	virtual int  getThreadID() const;							//获得线程ID
	virtual BOOL isRun() const;									//判断线程是否运行
	virtual void runTask() = 0;									//子类实现此函数完成业务逻辑
	//
	static unsigned _stdcall threadFunc(void* pParam);			//线程函数,调RunTask逻辑

protected:
	HANDLE m_hEndEvent;                                         //设置退出线程处理
	HANDLE m_hExitEvent;                                        //线程RunTask结束时设置,确保线程正常退出                                     
	HANDLE m_hThreadHandle;
	unsigned int m_uThreadID;
	//
};
