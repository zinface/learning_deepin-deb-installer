#ifndef PACKAGELISTVIEW_H
#define PACKAGELISTVIEW_H

#include <QListView>

class PackageListView : public QListView
{
    Q_OBJECT
public:
    explicit PackageListView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // PACKAGELISTVIEW_H
