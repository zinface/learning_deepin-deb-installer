#include "debinstaller.h"
#include "debinstallworker.h"
#include "deblistmodel.h"
#include "singleinstallpage.h"
#include "multipleinstallpage.h"

#include <QtGui>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QScreen>

#include <QApt/DebFile>

using QApt::DebFile;

DWIDGET_USE_NAMESPACE

DebInstaller::DebInstaller(QWidget *parent)
    : QWidget(parent),
      m_centralLayout(new QStackedLayout),
      m_fileChooseWidget(new FileChooseWidget),
      m_installWorker(new DebInstallWorker(this)),
      m_fileListModel(new DebListModel(this))
{
    m_centralLayout->addWidget(m_fileChooseWidget);
    setLayout(m_centralLayout);
    setFixedSize(480, 380);
    setWindowTitle("MDM Deb Installer");
    setWindowIcon(QIcon(":/images/icon.png"));
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
        if (!p->isValid()) {
            qWarning() << "package invalid: " << p->filePath();

            delete p;
            continue;
        }

        m_fileListModel->appendPackage(p);
    }

    const int packageCount = m_fileListModel->preparedPackages().size();
    // no packages found
    if(packageCount == 0)
        return;

    if (packageCount == 1) {
        // single package install
//        SingleInstallPage *singlePage = new  SingleInstallPage;
//        singlePage->setPackage(m_fileListModel->preparedPackages().first());
        SingleInstallPage *singlePage = new SingleInstallPage(m_fileListModel);

        m_centralLayout->addWidget(singlePage);
    } else {
        // multiple package installA
        MultipleInstallPage *multiplePage = new MultipleInstallPage(m_fileListModel);

        m_centralLayout->addWidget(multiplePage);
    }

    // switch to new page
    m_centralLayout->setCurrentIndex(1);
}
