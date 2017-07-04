#pragma once
#include<QString>
#include<sstream>
#include<string>

using std::string;


class CCodecUtils
{
public:
	static QString str2qstr(const string str)
	{
		return QString::fromLocal8Bit(str.data());
	}

	static string qstr2str(const QString qstr)
	{
		QByteArray cdata = qstr.toLocal8Bit();
		return string(cdata);
	}
	static string byte2HexCpp(const string & s)
	{
		std::ostringstream out;
		out << std::hex;
		for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		{
			// AND 0xFF will remove the leading "ff" in the output,
			// So that we could get "\xab" instead of "\xffab"
			out /*<< "0x"*/ << (static_cast<char>(*it) & 0xff) << " ";
		}
		return out.str();
	}

	static string hexStr2Str(const string & s)
	{
		char str[] = "0123456789ABCDEF";
		
		int n;
		string strOut;
		int nLen = s.length() / 2;
		for (int i = 0; i < nLen; i++)
		{
			strOut.append(1, (char)((hexCharToInt(s.at(i*2)) << 4)
				| hexCharToInt(s.at(i*2 + 1))));	
		}
		
		//
		return strOut;
	}

	static void byte2Hex(char *ptr, unsigned char *buf, int len)
	{
		for (int i = 0; i < len; i++)
		{
			sprintf(ptr, "%02x", buf[i]);
			ptr += 2;
		}
	}

	static string eraseSpace(string & str)
	{
		int nLen = str.length();
		string strOut;
		for (int i = 0; i < nLen; ++i)
		{
			if (str[i] != ' ')
			{
				strOut.append(1,str[i]);
			}
		}
		return strOut;
	}
	static int hexCharToInt(char c)
	{
		if (c >= '0' && c <= '9') return (c - '0');
		if (c >= 'A' && c <= 'F') return (c - 'A' + 10);
		if (c >= 'a' && c <= 'f') return (c - 'a' + 10);
		return 0;
	}
};