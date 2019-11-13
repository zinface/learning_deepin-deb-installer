#ifndef SINGLEINSTALLPAGE_H
#define SINGLEINSTALLPAGE_H

#include <QLabel>
#include <QWidget>
#include <QApt/DebFile>
#include <QApt/Backend>
#include <QPushButton>

class DebListModel;
class SingleInstallPage : public QWidget
{
    Q_OBJECT
public:
    explicit SingleInstallPage(DebListModel *model, QWidget *parent = nullptr);

private slots:
    void install();

private:
    void setPackageInfo();

private:
    DebListModel *m_packagesModel;
    QLabel *m_packageIcon;
    QLabel *m_packageName;
    QLabel *m_packageVersion;
    QLabel *m_packageDescription;
    QPushButton *m_installButton;
};

#endif // SINGLEINSTALLPAGE_H
