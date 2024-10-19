//source: https://metanit.com/cpp/tutorial/7.13.php

#include <iostream>
#include <set>
 
int main()
{
    std::set<int> numbers;   // пустое множество чисел int
    
    numbers = {1, 2, 3};
 
    std::cout << "Empty: " << std::boolalpha <<  numbers.empty() << std::endl;    // Empty: false
    std::cout << "Size: " << numbers.size() << std::endl;     // Size: 3
    
    numbers = {1, 2, 3, 4, 5};
 
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(2);
    numbers.insert(2);
    numbers.insert(6);
 
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    
    numbers.erase(7);
    numbers.erase(2);
    numbers.erase(3);
 
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    
    std::cout << "10 is in set: " << numbers.count(10) << std::endl;    // 10 is in set: 0
    std::cout << "4 is in set: " << numbers.count(4) << std::endl;      // 4 is in set: 1
    
}
