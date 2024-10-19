//source: https://metanit.com/cpp/tutorial/7.11.php

#include <iostream>
#include <queue>
 
int main()
{
    std::queue<std::string> queue;  // пустая очередь
    
    if (queue.empty())
    {
        std::cout << "queue is empty" << std::endl;
    }
    std::cout << "queue size: " << queue.size() << std::endl; // queue size: 0
    
    queue.push("Tom");
    queue.push("Bob");
    queue.push("Sam");
 
    std::cout << "queue size: " << queue.size() << std::endl; // queue size: 3
    
    std::cout << "First: " << queue.front() << std::endl;   // First: Tom
    std::cout << "Last: " << queue.back() << std::endl;     // Last: Sam
    
    while (!queue.empty())  // пока очередь не пуста
    {
        std::cout << queue.front() << std::endl;
        queue.pop();    // извлекаем первый элемент
    }
}
