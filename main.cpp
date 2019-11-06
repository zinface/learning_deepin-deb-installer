#include "debinstaller.h"

#include <DApplication>

using Dtk::Widget::DApplication;

int main(int argc, char *argv[])
{
    DApplication a(argc, argv);
    a.setOrganizationName("deepin");
    a.setApplicationName("MDM_INSTALLER");
    a.setApplicationVersion("1.0");
    a.setTheme("light");

    DebInstaller w;
    w.show();

    return a.exec();
}
