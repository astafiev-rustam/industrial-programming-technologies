//source: https://metanit.com/cpp/tutorial/16.3.php

#include <iostream>
#include <vector>
#include <algorithm>
 
// если число четное
bool is_even(int n){ return n % 2 == 0;}
// если число положительное
bool is_positive(int n){ return n > 0;}
 
// для вывода вектора на консоль
void print (const std::vector<int>& data)
{
    for(const auto& n: data)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
 }
 
int main()
{
    std::vector<int> numbers { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    std::vector<int> even_numbers (numbers.size());
    std::vector<int> pos_numbers (numbers.size());
 
    auto end_even_iter = std::copy_if(begin(numbers), end(numbers), begin(even_numbers), is_even);
    even_numbers.erase(end_even_iter, end(even_numbers));
    print(even_numbers);   //   -4      -2      0       2       4
 
    auto end_pos_iter = std::copy_if(begin(numbers), end(numbers), begin(pos_numbers), is_positive);
    pos_numbers.erase(end_pos_iter, end(pos_numbers));
    print(pos_numbers);   //    1       2       3       4       5
}
