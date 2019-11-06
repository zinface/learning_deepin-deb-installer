#ifndef DEBLISTMODEL_H
#define DEBLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include <DebFile>

class DebListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DebListModel(QObject *parent = nullptr);
    ~DebListModel();

    enum PackageRole
    {
        PackageNameRole = Qt::DisplayRole,
        UnusedRole = Qt::UserRole,
        PackageVersionRole,
        PackagePathRole,
        PackageDescriptionRole,
    };

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    const QList<QApt::DebFile *> preparedPackages() const {return m_preparedPackages;}

public slots:
    void appendPackage(QApt::DebFile *package);

private:
    QList<QApt::DebFile *> m_preparedPackages;


};

#endif // DEBLISTMODEL_H
