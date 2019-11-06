#ifndef DEBLISTMODEL_H
#define DEBLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>

class DebPackage;
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

    const QList<DebPackage *> preparedPackages() const {return m_preparedPackages;}

public slots:
    void appendPackage(DebPackage *package);

private:
    QList<DebPackage *> m_preparedPackages;


};

#endif // DEBLISTMODEL_H
