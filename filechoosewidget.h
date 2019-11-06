#ifndef FILECHOOSEWIDGET_H
#define FILECHOOSEWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPushButton>

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

private slots:
    void chooseFiles();

private:
    QPixmap m_bgImage;
    QPushButton *m_fileChooseBtn;
};

#endif // FILECHOOSEWIDGET_H
