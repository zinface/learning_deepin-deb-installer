#ifndef DEBLISTMODEL_H
#define DEBLISTMODEL_H

#include <QAbstractListModel>
#include <QFuture>
#include <QPointer>

#include <QApt/DebFile>
#include <QApt/Backend>
#include <QApt/Transaction>

class PackagesManager;
class DebListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DebListModel(QObject *parent = 0);

    enum InstallerStatus
    {
        InstallerPrepare,
        InstallerInstalling,
        InstallerFinished,
    };

    enum PackageRole
    {
        PackageNameRole = Qt::DisplayRole,
        UnusedRole = Qt::UserRole,
        PackageVersionRole,
        PackagePathRole,
        PackageDescriptionRole,
        PackageVersionStatusRole
    };

    enum PackageinstallStatus
    {
        NotInstalled,
        InstalledSameVersion,
        InstalledEarlierVersion,
        InstalledLaterVerision,
    };

    enum PackageDependsStatus
    {
        DependsOk,
        DependsAvailable,
        DependsBreak
    };

    enum PackageOperationStatus
    {
        Prepare,
        Operating,
        Success,
        Failed
    };

    const QList<QApt::DebFile *> preparedPackages() const;

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

signals:
    void installerStared() const;
    void installerFinished() const;
    void appendOutputInfo(const QString &info) const;
    void packageOperationChanged(const QModelIndex &index, int status) const;
    void packageDependsChanged(const QModelIndex &index, int status);

public slots:
    void installAll();
    void appendPackage(QApt::DebFile *package);

private:
    void installNextDeb();
    void fetchPackageInstallStatus(const QModelIndex &index);

private:
    int m_installerStatus;

    PackagesManager *m_packagesManager;

    QList<QApt::DebFile *>::iterator m_oplter;
    QPointer<QApt::Transaction> m_currentTransaction;

};

#endif // DEBLISTMODEL_H
