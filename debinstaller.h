#ifndef DEBINSTALLER_H
#define DEBINSTALLER_H


#include <QStackedLayout>
#include "filechoosewidget.h"

#include <DMainWindow>

class FileChooseWidget;
class DebInstallWorker;
class DebListModel;

class DebInstaller : public Dtk::Widget::DMainWindow
{
    Q_OBJECT
public:
    explicit DebInstaller(QWidget *parent = nullptr);
    ~DebInstaller();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void onPackagesSelected(const QStringList &packages);

private:
    QStackedLayout *m_centralLayout;
    FileChooseWidget *m_fileChooseWidget;

//    QList<DebPackage *> m_preparedPackages;
    DebInstallWorker *m_installWorker;
    DebListModel *m_fileListModel;
};

#endif // DEBINSTALLER_H
