#ifndef PACKAGESMANAGER_H
#define PACKAGESMANAGER_H

#include <QFuture>
#include <QObject>

#include <QApt/Backend>
#include <QApt/DebFile>

class DebListModel;
class PackagesManager : public QObject
{
    Q_OBJECT

    friend class DebListModel;

public:
    explicit PackagesManager(QObject *parent = nullptr);

    int packageInstallStatus(const int index);

private:
    QFuture<QApt::Backend *> m_backendFuture;
    QList<QApt::DebFile *> m_preparedPackages;
    QHash<int, int> m_packageInstallStatus;
    QHash<int, int> m_packageDependsStatus;
};

#endif // PACKAGESMANAGER_H
