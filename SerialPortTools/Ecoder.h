#pragma once
#include<string>
using std::string;
using std::wstring;

class CEcoder
{
public:
	CEcoder();
	~CEcoder();

	static void ansiToUnicode(const string & str, wstring & wstr);
	static wstring stringToWstring(const string & str);
	static string wstringToString(const wstring & wstr);
};


