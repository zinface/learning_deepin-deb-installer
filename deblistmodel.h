#ifndef DEBLISTMODEL_H
#define DEBLISTMODEL_H

#include <QAbstractListModel>
#include <QFuture>

#include <QApt/DebFile>
#include <QApt/Backend>

class DebListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DebListModel(QObject *parent = 0);
    ~DebListModel();

    enum PackageRole
    {
        PackageNameRole = Qt::DisplayRole,
        UnusedRole = Qt::UserRole,
        PackageVersionRole,
        PackagePathRole,
        PackageDescriptionRole,
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

    int packageInstallStatus(const QModelIndex &index);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    const QList<QApt::DebFile *> preparedPackages() const { return m_preparedPackages; }

public slots:
    void installAll();
    void installPackage(const QModelIndex &index);
    void appendPackage(QApt::DebFile *package);

private:
    QFuture<QApt::Backend *> m_backendFuture;
    QList<QApt::DebFile *> m_preparedPackages;
    QHash<int, int> m_packageInstallStatus;
    QHash<int, int> m_packageDependsStatus;
};

#endif // DEBLISTMODEL_H
