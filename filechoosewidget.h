#ifndef FILECHOOSEWIDGET_H
#define FILECHOOSEWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>

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
    void paintEvent(QPaintEvent *event);

private:
    QPixmap m_bgImage;

};

#endif // FILECHOOSEWIDGET_H
