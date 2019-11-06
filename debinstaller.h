#ifndef DEBINSTALLER_H
#define DEBINSTALLER_H

#include <QWidget>
#include <QStackedLayout>
#include "filechoosewidget.h"

class DebInstaller : public QWidget
{
    Q_OBJECT
public:
    explicit DebInstaller(QWidget *parent = nullptr);
    ~DebInstaller();

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QStackedLayout *m_centralLayout;
    FileChooseWidget *m_fileChooseWidget;


};

#endif // DEBINSTALLER_H
