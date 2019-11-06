#include "debinstaller.h"
#include "debinstallworker.h"
#include "deblistmodel.h"
#include "singleinstallpage.h"

#include <QtGui>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QScreen>

#include <QApt/DebFile>

using QApt::DebFile;

DebInstaller::DebInstaller(QWidget *parent)
    : DMainWindow(parent),
      m_centralLayout(new QStackedLayout),
      m_fileChooseWidget(new FileChooseWidget),
      m_installWorker(new DebInstallWorker(this)),
      m_fileListModel(new DebListModel(this))
{
    m_centralLayout->addWidget(m_fileChooseWidget);
    setLayout(m_centralLayout);
    setFixedSize(480, 380);
    setWindowTitle("MDM Deb Installer");
    move(qApp->primaryScreen()->geometry().center() - geometry().center());

    connect(m_fileChooseWidget, &FileChooseWidget::packagesSelected, this, &DebInstaller::onPackagesSelected);
}

DebInstaller::~DebInstaller()
{

}

void DebInstaller::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Escape:    qApp->quit();   break;
    default:;
    }
}

void DebInstaller::onPackagesSelected(const QStringList &packages)
{
    Q_ASSERT(m_fileListModel->preparedPackages().isEmpty());

    for (const auto &package : packages)
    {
        DebFile *p = new DebFile(package);

        m_fileListModel->appendPackage(p);
    }

    SingleInstallPage *singlePage = new  SingleInstallPage;
    singlePage->setPackage(m_fileListModel->preparedPackages().first());

    m_centralLayout->addWidget(singlePage);
    m_centralLayout->setCurrentIndex(1);
}
