### 1. Виртуальные функции

Виртуальные функции позволяют реализовать полиморфизм в C++. Они позволяют вызывать переопределенные функции в производных классах через указатель или ссылку на базовый класс.

```cpp
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show();  // Вызовется функция show() из Derived
    delete basePtr;
    return 0;
}
```

**Пояснение:** В этом примере функция `show()` в классе `Base` объявлена как виртуальная. Это позволяет вызывать переопределенную версию этой функции из класса `Derived` через указатель на базовый класс.

---

### 2. Абстрактные классы

Абстрактный класс — это класс, который содержит хотя бы одну чисто виртуальную функцию. Он не может быть инстанциирован, но может использоваться как базовый класс для других классов.

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() = 0;  // Чисто виртуальная функция
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw();  // Вызовется функция draw() из Circle
    delete shape;
    return 0;
}
```

**Пояснение:** Класс `Shape` является абстрактным, так как содержит чисто виртуальную функцию `draw()`. Класс `Circle` реализует эту функцию, и объект `Circle` может быть создан и использован через указатель на `Shape`.

---

### 3. Шаблон функции

Шаблоны функций позволяют создавать функции, которые могут работать с разными типами данных.

```cpp
#include <iostream>

// Шаблон функции для сложения
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Пользовательский класс
class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Переопределение оператора сложения
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Переопределение оператора вывода для удобства
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    // Пример с int
    std::cout << add(3, 4) << std::endl;          // Работает с int

    // Пример с double
    std::cout << add(3.5, 4.5) << std::endl;      // Работает с double

    // Пример с пользовательским классом Point
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = add(p1, p2);  // Используется переопределенный оператор +
    std::cout << p3 << std::endl;  // Вывод: (4, 6)

    return 0;
}
```

**Пояснение:** Шаблон функции `add` работает для любых типов, поддерживающих оператор `+`, включая встроенные типы (`int`, `double`) и пользовательские классы. 
Пользовательский класс `Point` переопределяет оператор сложения (`+`), чтобы можно было складывать два объекта `Point`, переопределяет оператор вывода (`<<`), 
чтобы удобно выводить объекты `Point` в консоль. Использование шаблона `add` для `int` и `double` используется стандартный оператор `+`, для `Point` 
используется переопределенный оператор `+`.

---

### 4. Шаблон классов

Шаблоны классов позволяют создавать классы, которые могут работать с разными типами данных.

```cpp
#include <iostream>

template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() const {
        return value;
    }
};

int main() {
    Box<int> intBox(123);
    Box<std::string> strBox("Hello");

    std::cout << intBox.getValue() << std::endl;  // 123
    std::cout << strBox.getValue() << std::endl;  // Hello
    return 0;
}
```

**Пояснение:** Класс `Box` может хранить значение любого типа. В примере показано использование с `int` и `std::string`.

---

### 5. Особенности шаблонов функций и классов

Шаблоны функций и классов могут быть специализированы для конкретных типов данных, что позволяет оптимизировать или изменить поведение для определенных случаев.

```cpp
#include <iostream>

template <typename T>
void print(T value) {
    std::cout << "Generic template: " << value << std::endl;
}

template <>
void print<int>(int value) {
    std::cout << "Specialized template for int: " << value << std::endl;
}

int main() {
    print(3.14);  // Используется общий шаблон
    print(42);    // Используется специализированный шаблон для int
    return 0;
}
```

**Пояснение:** В этом примере общий шаблон функции `print` работает для всех типов, но для типа `int` создана специализированная версия, которая выводит дополнительное сообщение.

---

### 6. Исключения

Исключения позволяют обрабатывать ошибки в программе, не прерывая её выполнение.

```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
```

**Пояснение:** В этом примере функция `divide` выбрасывает исключение `std::invalid_argument`, если делитель равен нулю. В блоке `try-catch` это исключение перехватывается и обрабатывается.
