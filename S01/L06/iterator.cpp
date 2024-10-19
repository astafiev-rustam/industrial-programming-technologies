//source: https://metanit.com/cpp/tutorial/7.3.php

#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> numbers{ 10, 20, 30, 40 };
    auto iter { numbers.begin() };  // получаем итератор
 
    while(iter!=numbers.end())    // пока не дойдем до конца
    {
        std::cout << *iter << std::endl;// получаем элементы через итератор
        ++iter;             // перемещаемся вперед на один элемент
    }
 
    // аналогичный пример с циклом for
    for(auto start{numbers.begin()}; start !=numbers.end(); start++ )
    {
        std::cout << *start << std::endl;
    }
}
