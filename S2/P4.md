# Пример 1
```C++
#include <iostream>

using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Унаследованный метод
    dog.bark(); // Собственный метод
    return 0;
}
```
# Пример 2
```C++
#include <iostream>

using namespace std;

class Animal {
public:
    void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Woof!" << endl;
    }
};

int main() {
    Dog dog;
    dog.makeSound(); // Woof!
    return 0;
}
```
# Пример 3
```C++
#include <iostream>

using namespace std;

class Animal {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
};

class Dog : public Animal {
public:
    void display() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Dog dog;
    dog.setName("Buddy");
    dog.display(); // Name: Buddy
    return 0;
}
```
# Пример 4
```C++
#include <iostream>

using namespace std;

class Animal {
public:
    void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    using Animal::makeSound; // Делаем метод базового класса доступным
    void makeSound() {
        cout << "Woof!" << endl;
    }
};

int main() {
    Dog dog;
    dog.makeSound();       // Woof!
    dog.Animal::makeSound(); // Animal sound
    return 0;
}
```
# Пример 5
```C++
#include <iostream>

using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

class Mammal {
public:
    void breathe() {
        cout << "Mammal is breathing" << endl;
    }
};

class Dog : public Animal, public Mammal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();    // Animal is eating
    dog.breathe(); // Mammal is breathing
    dog.bark();   // Dog is barking
    return 0;
}
```
