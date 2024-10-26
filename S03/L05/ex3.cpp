#include <QApplication>
#include <QStandardItemModel>
#include <iostream>
 
void printItems(const QStandardItem* parent, int level = 0)
{
 
    for(int i{};i<parent->rowCount(); i++)
    {
        for(int j{}; j < level; j++)
        {
            std::cout << "  ";  // для отделения дочерних узлов выводим пробелы
        }
        QStandardItem* item = parent->child(i, 0);
        std::cout << item->data(Qt::DisplayRole).toString().toStdString() << std::endl;
        printItems(item, level+1);
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    QStandardItemModel model;
    QStandardItem* parentItem = model.invisibleRootItem();
    QStandardItem* languages = new QStandardItem("Languages");
    QStandardItem* databases = new QStandardItem("Databases");
 
    parentItem->appendRow(languages);
    parentItem->appendRow(databases);
 
    languages->appendRow(new QStandardItem("C++"));
    languages->appendRow(new QStandardItem("Python"));
 
    databases->appendRow(new QStandardItem("MySQL"));
    databases->appendRow(new QStandardItem("PostgreSQL"));
 
    printItems(parentItem);
 
    return a.exec();
}
