#ifndef DEBINSTALLER_H
#define DEBINSTALLER_H

#include <QWidget>
#include <QStackedLayout>
#include "filechoosewidget.h"

class DebPackage;
class FileChooseWidget;


class DebInstaller : public QWidget
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

    QList<DebPackage *> m_preparedPackages;
};

#endif // DEBINSTALLER_H
