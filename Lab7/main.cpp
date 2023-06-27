#include <QApplication>
#include <QtPlugin>
#include "MainWindow.h"

Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return QApplication::exec();
}
