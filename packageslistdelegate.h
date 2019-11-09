#ifndef PACKAGESLISTDELEGATE_H
#define PACKAGESLISTDELEGATE_H

#include <QAbstractItemDelegate>

class PackagesListDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
    explicit PackagesListDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QPixmap m_packageIcon;
};

#endif // PACKAGESLISTDELEGATE_H
