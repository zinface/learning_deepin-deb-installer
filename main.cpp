#include "debinstaller.h"

#include <DApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QTimer>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);
    app.setOrganizationName("deepin");
    app.setApplicationName("MDM_INSTALLER");
    app.setApplicationVersion("1.0");
    app.setTheme("light");

    // command line arguments
    QCommandLineParser parser;
    parser.setApplicationDescription("Deepin deb package installer.");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("filename", QApplication::translate("main", "Deb Package path."), "file [file..]");

    parser.process(app);

    const QStringList file_list = parser.positionalArguments();
    qDebug() << file_list;

    DebInstaller w;
    w.show();

    // select files from args
    if(!file_list.isEmpty())
        QMetaObject::invokeMethod(&w, "onPackagesSelected", Qt::QueuedConnection, Q_ARG(QStringList, file_list));

    return app.exec();
}
