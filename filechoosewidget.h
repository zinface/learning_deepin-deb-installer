#ifndef FILECHOOSEWIDGET_H
#define FILECHOOSEWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPushButton>

#include <dlinkbutton.h>

class FileChooseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileChooseWidget(QWidget *parent = nullptr);


signals:
    void packagesSelected(const QStringList files) const;

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private slots:
    void chooseFiles();

private:
    Dtk::Widget::DLinkButton *m_fileChooseBtn;
};

#endif // FILECHOOSEWIDGET_H
