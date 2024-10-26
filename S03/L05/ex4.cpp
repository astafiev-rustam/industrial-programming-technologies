#include <QApplication>
#include <QListView>
#include <QStringListModel>
 
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    QWidget* widget = new QWidget;
    widget->setWindowTitle("METANIT.COM");
    widget->setMinimumHeight(150);
    widget->setMinimumWidth(250);
 
    // определяем данные для модели
    QStringList list = { "Tom", "Bob", "Sam" };
    // определяем модель
    QStringListModel *model = new QStringListModel(list);
 
    // определяем представление
    QListView *view = new QListView(widget);
    // устанавливаем модель для представления
    view->setModel(model);
 
    widget->show();
    return a.exec();
}
