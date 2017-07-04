#pragma once
#include<QFile>
#include<QApplication>

class CQssHelper
{
public:
	static void setStyle(const QString &style)
	{
		QFile qss(style);
		if (qss.open(QFile::ReadOnly))
		{
			qApp->setStyleSheet(qss.readAll());
			qss.close();
		}
	}
};
