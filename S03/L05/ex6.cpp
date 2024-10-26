#include <QApplication>
#include <QTreeView>
#include <QStandardItemModel>
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    QWidget* widget = new QWidget;
    widget->setWindowTitle("METANIT.COM");
    widget->setMinimumHeight(150);
    widget->setMinimumWidth(250);
 
    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *parentItem = model->invisibleRootItem();
    QStandardItem *languages = new QStandardItem("Языки программирования");
    QStandardItem *databases = new QStandardItem("Базы данных");
 
    parentItem->appendRow(languages);
    parentItem->appendRow(databases);
 
    languages->appendRow(new QStandardItem("C++"));
    languages->appendRow(new QStandardItem("Python"));
 
    databases->appendRow(new QStandardItem("MySQL"));
    databases->appendRow(new QStandardItem("PostgreSQL"));
 
 
    QTreeView *view = new QTreeView(widget);
    view->setModel(model);
 
    widget->show();
    return a.exec();
}
