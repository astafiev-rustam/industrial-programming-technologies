//source: https://metanit.com/cpp/tutorial/16.2.php

#include <iostream>
#include <vector>
#include <algorithm>
  
// если число четное
bool is_even(int n){ return n % 2 == 0;}
// если число положительное
bool is_positive(int n){ return n > 0;}
// если число больше 10
bool is_greater10(int n){ return n > 10;}
 
template <typename T>
void findValueIf (const std::vector<T>& data, bool(*condition)(T))
{
    auto result{ std::find_if(begin(data), end(data), condition) };
    if (result == end(data))
        std::cout << "Value not found" << std::endl;
    else
        std::cout << "Value found at position " << (result - begin(data)) << std::endl;
}

void findValue (const std::vector<int>& data, int value)
{
    auto result{ std::find(begin(data), end(data), value) };
    if (result == end(data))
        std::cout << "Value not found" << std::endl;
    else
        std::cout << "Value found at position " << (result - begin(data)) << std::endl;
 }
 
int main()
{
    std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8};
    findValue(numbers, 4);    // Value found at position 3 
    findValue(numbers, 12);   // Value not found
    
    numbers = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    findValueIf(numbers, is_even);        // Value found at position 1
    findValueIf(numbers, is_positive);    // Value found at position 6
    findValueIf(numbers, is_greater10);   // Value not found
}
