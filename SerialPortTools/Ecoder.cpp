#include "stdafx.h"
#include <Windows.h>
#include <objbase.h.>
#include <tchar.h>
#include "Ecoder.h"

CEcoder::CEcoder()
{
}


CEcoder::~CEcoder()
{
}

void CEcoder::ansiToUnicode(const string & str, wstring & wstr)
{
	int nlenstr = lstrlenA(str.c_str());
	int nlenwstr = 0;
	WCHAR * unicodestr = NULL;
	
	nlenwstr = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), nlenstr, 0, 0);
	if (nlenwstr > 0)
	{
		unicodestr = ::SysAllocStringLen(0, nlenwstr);
		::MultiByteToWideChar(CP_ACP, 0, str.c_str(), nlenstr, unicodestr, nlenwstr);

	}
	else
	{
		wstr = _T(""); //nothing
	}
	wstr = unicodestr;
	::SysFreeString(unicodestr);
}

wstring CEcoder::stringToWstring(const string & str)
{
	LPCSTR pszSrc = str.c_str();
	int nLen = MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, NULL, 0);
	if (nLen == 0)
		return wstring(L"");

	wchar_t* pwszDst = new wchar_t[nLen];
	if (!pwszDst)
		return wstring(L"");

	MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, pwszDst, nLen);
	std::wstring wstr(pwszDst);
	delete[] pwszDst;
	pwszDst = NULL;
	return wstr;
}

string CEcoder::wstringToString(const wstring & wstr)
{
	LPCWSTR pwszSrc = wstr.c_str();
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
		return string("");

	char* pszDst = new char[nLen];
	if (!pszDst)
		return string("");

	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	string str(pszDst);
	delete[] pszDst;
	pszDst = NULL;

	return str;
}