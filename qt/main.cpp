#include <QApplication>

#include "radiobuttons.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	RadioButtons window;

	window.show();
	return app.exec();
}
