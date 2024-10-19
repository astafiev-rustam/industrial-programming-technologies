//source: https://metanit.com/cpp/tutorial/7.14.php

#include <iostream>
#include <map>
 
int main()
{
    std::map<std::string, unsigned> products;
    // установка значений
    products["bread"] = 30;
    products["milk"] = 80;
    products["apple"] = 60;
 
    // получение значений
    std::cout << "bread\t" << products["bread"] << std::endl;
    std::cout << "milk\t" << products["milk"] << std::endl;
    std::cout << "apple\t" << products["apple"] << std::endl;
    
    for (const auto& [product, price] : products)
        std::cout << product << "\t" << price << std::endl;
        
    products.erase("milk");   // удаляем элемент с ключом "milk"
 
    for (const auto& [product, price] : products)
        std::cout << product << "\t" << price << std::endl;
        
}
