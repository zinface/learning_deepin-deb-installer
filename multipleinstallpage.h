#ifndef MULTIPLEINSTALLPAGE_H
#define MULTIPLEINSTALLPAGE_H

#include <QWidget>
#include <QPushButton>

class PackageListView;
class DebListModel;
class MultipleInstallPage : public QWidget
{
    Q_OBJECT
public:
    explicit MultipleInstallPage(DebListModel *model, QWidget *parent = nullptr);


private:
    DebListModel *m_debListModel;
    PackageListView *m_appsView;
    QPushButton *m_installButton;
};

#endif // MULTIPLEINSTALLPAGE_H
