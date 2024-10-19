//source: https://metanit.com/cpp/tutorial/7.2.php

#include <iostream>
#include <vector>
  
int main()
{
    std::vector<int> numbers {1, 2, 3, 4, 5};
     
    int first = numbers.front();    // 1
    int last = numbers.back();      // 5
    int second = numbers[1];        // 2
    std::cout << "first: " << first << std::endl;
    std::cout << "second: " << second << std::endl;
    std::cout << "last: " << last << std::endl;
 
    numbers[0] = 6;  // изменяем значение   
    for(int n : numbers)
        std::cout << n << "\t"; // 6  2  3  4  5
     
    std::cout << std::endl;
}
