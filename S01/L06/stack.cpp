//source: https://metanit.com/cpp/tutorial/7.10.php

#include <iostream>
#include <stack>
 
int main()
{
    std::stack<std::string> stack;
    if(stack.empty())
    {
        std::cout << "stack is empty" << std::endl;
    }
    std::cout << "stack size: " << stack.size() << std::endl; // stack size: 0
    
    stack.push("Tom");
    stack.push("Bob");
    stack.push("Sam");
 
    std::cout << "stack size: " << stack.size() << std::endl; // stack size: 3
    
    std::cout << "Top: " << stack.top() << std::endl;   // Top: Sam
    
    stack.pop();
    std::cout << "Top: " << stack.top() << std::endl;
    
    stack.push("Krash");
    stack.push("Masik");
    stack.push("Tybik");
 
    while (!stack.empty())  // пока стек не пуст
    {
        std::cout << stack.top() << std::endl;
        stack.pop();    // извлекаем верхний элемент
    }
}
