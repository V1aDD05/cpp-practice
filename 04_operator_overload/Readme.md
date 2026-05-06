# Класс для работы с рациональными числами
Код является **переработанным** решением [заданий из урока курса](https://stepik.org/lesson/559/step/1?unit=882)

## Состав директории
- Readme;
- `src` директория 
-- Заголовочный файл `rational.hpp`, содержащий объявление класса для работы с рациональными числами `Rational`;
- Файл `CMakeLists.txt`, содержащий инструкции по сборке совместно с тестами;
- `tests` директория
-- Файл `test_rational.cpp`, содержащий тесты

## Особенности
- Класс `Rational`, содержащий публичные интерфейсы, и основанные на них свободные функции;
- Проверка деления на ноль реализована при помощи `assert`;
- Не реализована обработка исключений;
- Не реализована проверка неправильного пользовательского ввода;
- Преобразование `Rational` в `double` при помощи `to_double` может приводить к потенциальной потере точности.
- Реализовано тестирование при помощи `Google Tests`

## Интерфейс
### Методы класса
- `int get_numerator()` - геттер числителя;
- `int get_denominator()` - геттер знаменателя;
- `+=`, `-=`, `*=`, `/=` - составные операторы;
- `+`, `-` - унарные операторы;
- `to_double()` - преобразование в `double`.

### Свободные функции
- `+`, `-`, `*`, `/` - бинарные операторы (реализованы через `составные операторы` класса);
- `==`, `!=`, `>`, `<`, `>=`, `<=` - операторы сравнения (реализованы при помощи `геттеров` класса);
- `<<`, `>>` - ввод и вывод.

## Сборка и тестирование

Для сборки проекта потребуется `CMake` (>=v.3.15) и компилятор с поддержкой C++17.

**Шаги сборки и тестирования:**
1. Клонируйте репозиторий.
2. Перейдите в директорию `04_operator_overload` и создайте папку для сборки:
```sh
cd 04_operator_overload
mkdir build && cd build
```
3. Сгенерируйте файлы сборки:
```sh
cmake ..
```

4. Соберите проект:
```sh
cmake --build .
```

5. Запустите тесты:
```sh
ctest --verbose
```

## Пример применения (без тестов)

Ниже показано, как использовать класс `Rational` в простой программе.

```cpp
#include <iostream>
#include <sstream>
#include "rational.hpp"

int main()
{
    // ввод и вызов конструктора
    std::istringstream input("2/5");
    Rational firstRational;
    input >> firstRational;

    // применение геттеров
    std::cout << "numerator is " << firstRational.get_numerator() << std::endl;

    Rational secondRational(10, 6);
    std::cout << "second rational is " << secondRational << std::endl;

    //Применение составных операторов
    secondRational *= firstRational;
    std::cout << "second rational after `*= firstRational` is " << secondRational << std::endl;

    //Применение унарных операторов
    Rational thirdRational = -secondRational;
    std::cout << "third rational after `-secondRational` is " << thirdRational << std::endl;

    //Применение бинарных операторов
    Rational fourthRational = secondRational + 3;
    std::cout << "fourth rational after `secondRational + 3` is " << fourthRational << std::endl;

    //Применение операторов сравнения
    std::cout << "is second rational == third rational? " << (secondRational == thirdRational) << std::endl;

}

```

### Скомпилировать и запустить можно командой
```sh
g++ -std=c++17 example.cpp -o example && ./example
```
Для этого необходимо заранее создать `example.cpp`, вставив код из примера выше или написав свой.