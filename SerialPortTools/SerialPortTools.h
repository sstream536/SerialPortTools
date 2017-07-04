#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_SerialPortTools.h"

#include<string>
using std::string;

class SerialPortTools : public QMainWindow
{
	Q_OBJECT

public:
	SerialPortTools(QWidget *parent = Q_NULLPTR);
	~SerialPortTools();
//
	private slots:
	void openPort();
	void closePort();
	void sendData();
	void reciveData();
protected:
	void enumPort(QStringList & strList);
	void MessageBoxInfo(const QString & strInfo, const QString & strContent);
private:
	Ui::SerialPortToolsClass ui;
	QAction * pOpenAction;
	QTimer m_timer;
	string m_strRec;
};
