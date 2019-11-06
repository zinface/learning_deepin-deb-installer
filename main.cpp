#include "debinstaller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("deepin");
    a.setApplicationName("MDM_INSTALLER");
    a.setApplicationVersion("1.0");

    DebInstaller w;

    w.show();

    return a.exec();
}
