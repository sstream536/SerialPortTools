#include "SerialPortTools.h"
#include <QtWidgets/QApplication>
#include "QssHelper.h"
#include <QtPlugin>

Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CQssHelper::setStyle(":SerialPortTools/qss/brown.css");
	SerialPortTools w;
	w.show();

	return a.exec();
}
