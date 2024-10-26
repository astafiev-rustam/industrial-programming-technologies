#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* widget = new QWidget;
    widget->setWindowTitle("METANIT.COM");
    widget->setMinimumHeight(800);
    widget->setMinimumWidth(1000);

    QStandardItemModel* model=  new QStandardItemModel(3, 2);
    model->setItem(0, 0, new QStandardItem("Tom"));
    model->setItem(0, 1, new QStandardItem("39"));
    model->setItem(1, 0, new QStandardItem("Bob"));
    model->setItem(1, 1, new QStandardItem("43"));
    model->setItem(2, 0, new QStandardItem("Sam"));
    model->setItem(2, 1, new QStandardItem("28"));

    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Age");

    QTableView *view = new QTableView(widget);
    view->setModel(model);

    view->selectColumn(1);
    view->sortByColumn(1, Qt::AscendingOrder);

    widget->show();
    return a.exec();
}
