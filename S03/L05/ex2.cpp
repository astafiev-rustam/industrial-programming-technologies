#include <QApplication>
#include <iostream>
#include <QStringListModel>
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    QStringList people = { "Tom", "Bob", "Sam"};
    // определяем модель
    QStringListModel *model = new QStringListModel(people);
 
    people.append("Alice");
    people.removeAll("Bob");
    people.replace(0, "Tomas");
 
    std::cout << "Model:" << std::endl;
    for(const auto &person: model->stringList()){
        std::cout << person.toStdString() << std::endl;
    }
 
    std::cout << "StringList:" << std::endl;
    for(const auto &person: people){
        std::cout << person.toStdString() << std::endl;
    }
    return a.exec();
}
