#ifndef SINGLEINSTALLPAGE_H
#define SINGLEINSTALLPAGE_H

#include <QLabel>
#include <QWidget>

class SingleInstallPage : public QWidget
{
    Q_OBJECT
public:
    explicit SingleInstallPage(QWidget *parent = nullptr);

private:
    QLabel *m_packageIcon;
    QLabel *m_packageName;
    QLabel *m_packageVersion;
    QLabel *m_packageDescription;
};

#endif // SINGLEINSTALLPAGE_H
