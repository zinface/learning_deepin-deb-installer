#include "deblistmodel.h"

#include <QApt/DebFile>
#include <QApt/Backend>

#include <QSize>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QDebug>

using namespace QApt;

Backend *init_backend()
{
    Backend *b = new Backend;
    if(b->init()){
        return b;
    }

    qFatal("%s", b->initErrorMessage().toStdString().c_str());
    return nullptr;
}

DebListModel::DebListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_backendFuture = QtConcurrent::run(init_backend);
}

DebListModel::~DebListModel()
{
    m_backendFuture.result()->deleteLater();

    qDeleteAll(m_preparedPackages);
}

int DebListModel::packageInstallStatus(const QModelIndex &index)
{
    const int r = index.row();

    if(m_packageInstallStatus.contains(r))
        return m_packageInstallStatus[r];

    const QString packageName = m_preparedPackages[r]->packageName();
    Backend *b = m_backendFuture.result();
    Package *p = b->package(packageName);

    const QString installVersion = p->installedVersion();
    if(installVersion.isEmpty())
    {
        m_packageDependsStatus.insert(r, NotInstalled);
        return NotInstalled;
    }

    const QString packageVersion = m_preparedPackages[r]->version();
    const int result = Package::compareVersion(packageVersion, installVersion);

    int ret;
    if(result == 0)
        ret = InstalledSameVersion;
    else if(result > 0)
        ret = InstalledLaterVerision;
    else
        ret = InstalledEarlierVersion;

    m_packageInstallStatus.insert(r, ret);
    return ret;
}

int DebListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_preparedPackages.size();
}

QVariant DebListModel::data(const QModelIndex &index, int role) const
{
    const int r = index.row();
    const DebFile *package = m_preparedPackages[r];

    switch (role) {
    case PackageNameRole:
        return package->packageName();
    case PackagePathRole:
        return package->filePath();
    case PackageVersionRole:
        return package->version();
    case PackageDescriptionRole:
        return package->shortDescription();
    case Qt::SizeHintRole:
        return QSize(0, 60);
    default:;
    }

    return QVariant();
}

void DebListModel::installAll()
{

}

void DebListModel::installPackage(const QModelIndex &index)
{
    Backend *b = m_backendFuture.result();
}

void DebListModel::appendPackage(DebFile *package)
{
    m_preparedPackages.append(package);

    // test
//    Backend *b = m_backendFuture.result();
//    Package *p = b->package(package->packageName());

    // 以下包含可可能复现未知问题,可能出于control规范
//    qDebug() << p->installedVersion();
}
