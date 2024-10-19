//source: https://metanit.com/cpp/tutorial/7.6.php

#include <iostream>
#include <list>

int main() {
    std::list<int> list1; // пустой список
    std::list<int> list2(5); // список list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
    std::list<int> list3(5, 2); // список list3 состоит из 5 чисел, каждое число равно 2
    std::list<int> list4{ 1, 2, 4, 5 }; // список list4 состоит из чисел 1, 2, 4, 5
    std::list<int> list5 = { 1, 2, 3, 5 }; // список list5 состоит из чисел 1, 2, 3, 5
    std::list<int> list6(list4); // список list6 - копия списка list4
    std::list<int> list7 = list4; // список list7 - копия списка list4
    
    std::list<int> numbers{ 1, 2, 3, 4, 5 };
  
    int first {numbers.front() };  // 1
    int last { numbers.back() };  // 5
 
    std::cout << "First: " << first << std::endl;
    std::cout << "Last: " << last << std::endl;
  
    // перебор в цикле
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
  
    // перебор с помощью итераторов
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    
    numbers = { 1, 2, 3, 4, 5 };
    numbers.push_back(23);  // { 1, 2, 3, 4, 5, 23 }
    numbers.push_front(15); // { 15, 1, 2, 3, 4, 5, 23 }
    numbers.emplace_back(24);   // { 15, 1, 2, 3, 4, 5, 23, 24 }
    numbers.emplace_front(14);  // { 14, 15, 1, 2, 3, 4, 5, 23, 24 }
    
    numbers = { 1, 2, 3, 4, 5 };
    numbers.pop_front();    // numbers = { 2, 3, 4, 5 }
    numbers.pop_back();     // numbers = { 2, 3, 4 }
    numbers.clear();    // numbers ={}
 
    numbers = { 1, 2, 3, 4, 5 };
    auto iter = numbers.cbegin(); // указатель на первый элемент
    numbers.erase(iter);    // удаляем первый элемент
    // numbers = { 2, 3, 4, 5 }
 
    numbers = { 1, 2, 3, 4, 5 };
    auto begin = numbers.begin(); // указатель на первый элемент
    auto end = numbers.end();       // указатель на последний элемент
    numbers.erase(++begin, --end);  // удаляем со второго элемента до последнего
    //numbers = {1, 5}
}
