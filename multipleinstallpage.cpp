#include "deblistmodel.h"
#include "multipleinstallpage.h"
#include "packagelistview.h"
#include "packageslistdelegate.h"

#include <QVBoxLayout>

MultipleInstallPage::MultipleInstallPage(DebListModel *model, QWidget *parent)
    : QWidget (parent),
      m_appsView(new PackageListView),
      m_installButton(new QPushButton),
      m_debListModel(model)
{
    m_appsView->setModel(model);
    m_appsView->setItemDelegate(new PackagesListDelegate);
    m_installButton->setText("install");
    m_installButton->setFixedWidth(120);

    QVBoxLayout *centralLayout = new QVBoxLayout;

    centralLayout->addWidget(m_appsView);
    centralLayout->addWidget(m_installButton);
    centralLayout->setAlignment(m_installButton, Qt::AlignHCenter);

    setLayout(centralLayout);

    connect(m_installButton, &QPushButton::clicked, m_debListModel, &DebListModel::installAll);
}
