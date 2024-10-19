#include <iostream>
#include <vector>
  
void print(std::vector<int> numbers){
    for(int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
}

int main()
{
//---------------------------------------------------------------------------------
    //push_back
    std::vector<int> numbers;     // пустой вектор
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(10);
    print(numbers);                     //  5   3   10
//---------------------------------------------------------------------------------
    //emplace_back
    numbers = { 1, 2, 3, 4, 5 };
    numbers.emplace_back(8);    // numbers = { 1, 2, 3, 4, 5, 8 };
    print(numbers);
//---------------------------------------------------------------------------------
    //emplace
    numbers = { 1, 2, 3, 4, 5 };
    auto iter = numbers.cbegin();   // константный итератор указывает на первый элемент
    numbers.emplace(iter + 2, 8); // добавляем после второго элемента  numbers = { 1, 2, 8, 3, 4, 5};
    print(numbers);
//---------------------------------------------------------------------------------
    //insert
    std::vector<int> numbers1{ 1, 2, 3, 4, 5 };
    auto iter1 = numbers1.cbegin(); // константный итератор указывает на первый элемент
    numbers1.insert(iter1 + 2, 8); // добавляем после второго элемента  
    //numbers1 = { 1, 2, 8, 3, 4, 5};
    print(numbers1);
    
    std::vector<int> numbers2 { 1, 2, 3, 4, 5 };
    auto iter2 = numbers2.cbegin(); // константный итератор указывает на первый элемент
    numbers2.insert(iter2 + 1, 3, 4); // добавляем после первого элемента три четверки  
    //numbers2 = { 1, 4, 4, 4, 2, 3, 4, 5};
    print(numbers2);
    
    std::vector<int> values { 10, 20, 30, 40, 50 };
    std::vector<int> numbers3 { 1, 2, 3, 4, 5 };
    auto iter3 = numbers3.cbegin(); // константный итератор указывает на первый элемент
    // добавляем после первого элемента три первых элемента из вектора values
    numbers3.insert(iter3 + 1, values.begin(), values.begin() + 3);
    //numbers3 = { 1, 10, 20, 30, 2, 3, 4, 5};
    print(numbers3);
    
    std::vector<int> numbers4 { 1, 2, 3, 4, 5 };
    auto iter4 = numbers4.cend();   // константный итератор указывает на позицию за последним элементом
    // добавляем в конец вектора numbers4 элементы из списка { 21, 22, 23 }
    numbers4.insert(iter4, { 21, 22, 23 });
    //numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};
    print(numbers4);
//---------------------------------------------------------------------------------
}
