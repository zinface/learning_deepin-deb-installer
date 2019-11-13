#ifndef DEBINSTALLER_H
#define DEBINSTALLER_H


#include <QStackedLayout>
#include "filechoosewidget.h"

#include <DMainWindow>

class FileChooseWidget;
class DebListModel;

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

    void onOutputPrinted(const QString &output) const;

private:
    QStackedLayout *m_centralLayout;
    FileChooseWidget *m_fileChooseWidget;

    DebListModel *m_fileListModel;
};

#endif // DEBINSTALLER_H
