#include "mainwindow.h"
#include <QApplication>
#include <QFont>
#include <QDebug>
#include <QFontDatabase>
#include "common.h"
#include <QWindow>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	sharedResPath = QCoreApplication::applicationDirPath() + "/../share/rfsom-box-gui/";
	int id = QFontDatabase::addApplicationFont(resolveFileLocation("font/dejavu-fonts-ttf-2.37/ttf/DejaVuSansMono.ttf"));
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont monospace(family);
	monospace.setPointSize(10);

	QApplication::setFont(monospace);

	MainWindow w;

	// ✅ Replace fullscreen + frameless with standard window flags and resizable window
	w.setWindowFlags(Qt::Window);  // Allows title bar, resizing, minimize/maximize
	w.resize(1024, 768);           // Default size

	w.show();  // Show normally (not fullscreen)

	return a.exec();
}