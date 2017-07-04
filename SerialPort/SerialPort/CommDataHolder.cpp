#include "CommDataHolder.h"

std::shared_ptr<CCommDataHolder>  CCommDataHolder::s_pInstance(nullptr);
std::mutex CCommDataHolder::s_mt;

CCommDataHolder::CCommDataHolder()
{
	m_listData.clear();
}


CCommDataHolder::~CCommDataHolder()
{
}

std::shared_ptr<CCommDataHolder> CCommDataHolder::getInstance()
{
	if (!s_pInstance)
	{
		std::lock_guard<std::mutex> mt(s_mt);
		if (!s_pInstance)
		{
			s_pInstance.reset(new CCommDataHolder());
		}
	}
	return s_pInstance;
}

int CCommDataHolder::getDataCallBackS(list<char> & buffer)
{
	return s_pInstance->getDataCallBack(buffer);
}


int CCommDataHolder::getDataCallBack(list<char> & buffer)
{

	std::lock_guard<std::mutex> lgd(m_mt);
	if (!m_listData.empty())
	{
		m_listData.splice(m_listData.end(), buffer, buffer.begin(), buffer.end());
	}
	else
	{
		m_listData = buffer;
	}
	return m_listData.size();
}


int CCommDataHolder::getCommData(char * buffer, int len)
{
	if (buffer != NULL  && len != 0)
	{
		std::lock_guard<std::mutex> lgd(m_mt);
		if (m_listData.empty())
		{
			return 0;
		}
		int size = m_listData.size();
		int nLen = len > m_listData.size() ? size : len;
		list<char>::iterator it_inc = m_listData.begin();
		for (int i = 0; i < nLen; i++,++it_inc)
		{
			buffer[i] = *it_inc;
		}
		if (it_inc == m_listData.end())
		{
			m_listData.clear();
		}
		else
		{
			list<char> tmp(it_inc, m_listData.end());
			m_listData = tmp;
		}
		return nLen;
	}
	return 0;
}