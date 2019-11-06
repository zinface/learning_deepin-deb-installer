#include "debinstaller.h"

#include <QtGui>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QScreen>

DebInstaller::DebInstaller(QWidget *parent)
    : QWidget(parent),
      m_centralLayout(new QStackedLayout),
      m_fileChooseWidget(new FileChooseWidget)
{
    m_centralLayout->addWidget(m_fileChooseWidget);
    setLayout(m_centralLayout);
    resize(800, 600);
    move(qApp->primaryScreen()->geometry().center() - rect().center());
}

DebInstaller::~DebInstaller()
{

}

void DebInstaller::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Escape:    qApp->quit();   break;
    default:;
    }
}
