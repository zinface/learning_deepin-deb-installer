#include "packagelistview.h"

PackageListView::PackageListView(QWidget *parent)
    : QListView(parent)
{
    setVerticalScrollMode(ScrollPerPixel);
}
