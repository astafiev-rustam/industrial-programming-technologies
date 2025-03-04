# Пример 1
  ```C++
#include <iostream>

using namespace std;

void print(int i) {
    cout << "Integer: " << i << endl;
}

void print(double d) {
    cout << "Double: " << d << endl;
}

int main() {
    print(5);      // Вызов print(int)
    print(3.14);   // Вызов print(double)
    return 0;
}
  ```
# Пример 2
  ```C++
#include <iostream>

using namespace std;

template <typename T>
void print(T value) {
    cout << "Value: " << value << endl;
}

int main() {
    print(42);      // Вызов print<int>
    print("Hello"); // Вызов print<const char*>
    return 0;
}
  ```
# Пример 3
  ```C++
#include <iostream>

using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound(); // Woof!
    animal2->makeSound(); // Meow!

    delete animal1;
    delete animal2;
    return 0;
}
  ```
# Пример 4
  ```C++
#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Чисто виртуальная функция
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw(); // Drawing a circle
    shape2->draw(); // Drawing a square

    delete shape1;
    delete shape2;
    return 0;
}
  ```
