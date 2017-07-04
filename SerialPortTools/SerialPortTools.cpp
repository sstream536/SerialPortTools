#include "stdafx.h"
#include "SerialPortTools.h"
#include <Windows.h>
#include <tchar.h>
#include "Ecoder.h"
#include "CodecUtils.h"
#include "Qt5Serialport.h"
#include <QMessageBox>
#include <string>
using std::string;
using std::wstring;

SerialPortTools::SerialPortTools(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//
	QStringList strlist;
	enumPort(strlist);
	ui.comboBox->addItems(strlist);
	strlist.clear();
	strlist << "9600" << "19200" << "38400"<<"57600"<<"115200";
	ui.comboBox_2->addItems(strlist);
	strlist.clear();
	strlist << "5" << "6" << "7" << "8";
	ui.comboBox_3->addItems(strlist);
	strlist.clear();
	strlist << "None" << "Even" << "Odd" << "Mark" << "Space";
	ui.comboBox_4->addItems(strlist);
	strlist.clear();
	strlist << "1" << "1.5" << "2";
	ui.comboBox_5->addItems(strlist);
	//
	ui.radioButton->setChecked(true);
	ui.radioButton_3->setChecked(true);
	ui.comboBox_3->setCurrentIndex(3);
	//
	connect(ui.openaction, SIGNAL(triggered()),this,SLOT(openPort()));
	connect(ui.closeaction,SIGNAL(triggered()),this,SLOT(closePort()));
	connect(ui.pushButton, SIGNAL(clicked()),this,SLOT(sendData()));
	ui.closeaction->setEnabled(false);
	//
	m_timer.setInterval(2000);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(reciveData()));
}

SerialPortTools::~SerialPortTools()
{
	m_timer.stop();
}
//

void SerialPortTools::openPort()
{
	QString strCom = ui.comboBox->currentText();
	QString strBaudRate = ui.comboBox_2->currentText();
	QString strByteSize = ui.comboBox_3->currentText();
	//
	string com   = CCodecUtils::qstr2str(strCom);
	int baudRate = strBaudRate.toInt();
	int byteSize = strByteSize.toInt();
	int parity	 = ui.comboBox_4->currentIndex();
	int stopBit  = ui.comboBox_5->currentIndex();
	setCommConfig(com.c_str(), baudRate, byteSize, parity, stopBit);
	//
	start();	
	m_timer.start();
	MessageBoxInfo(tr("提示"), tr("    串口打开成功    "));
	ui.openaction->setEnabled(false);
	ui.closeaction->setEnabled(true);
}

void SerialPortTools::closePort()
{
	end();
	ui.openaction->setEnabled(true);
	ui.closeaction->setEnabled(false);
}

void SerialPortTools::sendData()
{
	QString str = ui.textEdit_2->toPlainText();
	string strSend = CCodecUtils::qstr2str(str);
	if (!strSend.empty())
	{
		//
		if (ui.radioButton_3->isChecked())
		{
			commWriteData(strSend.c_str(), strSend.length() + 1);
		}
		else if (ui.radioButton_4->isChecked())
		{
			string strtmp = CCodecUtils::hexStr2Str(CCodecUtils::eraseSpace(strSend));
			commWriteData(strtmp.c_str(),strtmp.length()+1);
			//
		}
	}
}

void SerialPortTools::reciveData()
{
	char szRead[1024] = { 0 };
	memset(&szRead, 0, 1024);
	int nRet = commReadData(szRead, 1024);
	m_strRec = CCodecUtils::qstr2str(ui.textEdit->toPlainText());
	if (nRet != 0)
	{
		string str = szRead;
		m_strRec += str;
		if (ui.radioButton->isChecked())
		{
			ui.textEdit->setText(CCodecUtils::str2qstr(m_strRec));
		}
		else if (ui.radioButton_2->isChecked())
		{
			char sz[2048];
			memset(&sz, 0, 2048);
			ui.textEdit->setText(CCodecUtils::str2qstr(CCodecUtils::byte2HexCpp(m_strRec)));
		}
	}	
}

void SerialPortTools::enumPort(QStringList & strList)
{
	HKEY hKey;
	LPCTSTR lpSubKey = _T("HARDWARE\\DEVICEMAP\\SERIALCOMM\\");

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpSubKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
	{
		return;
	}
	WCHAR szValueName[100] = { 0 };
	WCHAR szPortName[100] = { 0 };
	LONG status;
	DWORD dwIndex = 0;
	DWORD dwSizeValueName = 100;
	DWORD dwSizeofPortName = 100;
	DWORD Type;
	dwSizeValueName = 100;
	dwSizeofPortName = 100;
	do
	{
		status = RegEnumValue(hKey, dwIndex++, szValueName, &dwSizeValueName, NULL, &Type, (PUCHAR)szPortName, &dwSizeofPortName);
		if ((status == ERROR_SUCCESS))
		{
			QString tmp = CCodecUtils::str2qstr(CEcoder::wstringToString(szPortName));
			strList << tmp;
		}
		dwSizeValueName = 100;
		dwSizeofPortName = 100;
	} while ((status != ERROR_NO_MORE_ITEMS));
	RegCloseKey(hKey);
}

void SerialPortTools::MessageBoxInfo(const QString & strInfo, const QString & strContent)
{
	QMessageBox box(QMessageBox::NoIcon, strInfo, strContent);
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.exec();
}