//source: https://metanit.com/cpp/tutorial/16.6.php

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>     // для std::ranges только для стандарта 20 и выше
 
int main()
{
    std::vector<std::string> people {"Tom", "Bob", "Sam", "Alice", "Kate"};  
 
    std::ranges::sort(people);  // сортируем вектор people
 
    for(const auto& person: people )
    {
        std::cout << person << std::endl;
    }
}
