#ifndef MULTIPLEINSTALLPAGE_H
#define MULTIPLEINSTALLPAGE_H

#include <QWidget>
#include <QPushButton>

class PackageListView;
class QAbstractListModel;
class MultipleInstallPage : public QWidget
{
    Q_OBJECT
public:
    explicit MultipleInstallPage(QAbstractListModel *model, QWidget *parent = nullptr);


private:
    PackageListView *m_appsView;
    QPushButton *m_installButton;
};

#endif // MULTIPLEINSTALLPAGE_H
