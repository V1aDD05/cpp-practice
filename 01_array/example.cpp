#include <iostream>
#include <utility> //std::move
#include <cstddef> // size_t
#include "int_array.hpp"

int main()
{
    // проверка конструктора
    size_t firstSize = 10;
    IntArray firstArray(firstSize);

    // проверка доступа к элементу массива по ссылке
    // и чтения элемента массива
    std::cout << "Filling first array with values" << std::endl;
    for (size_t i = 0; i < firstSize; ++i)
    {
        firstArray.get(i) = static_cast<int>(i);
        std::cout << "No " << i << " = " << firstArray.get(i) << std::endl;
    }
    std::cout << std::endl;

    // проверка метода для получения информации о размере массива
    std::cout << "size of first array before resize = " << firstArray.size() << std::endl;
    std::cout << std::endl;

    // проверка метода изменения размеров массива в сторону увеличения
    size_t newSize = 12;
    firstArray.resize(newSize);
    std::cout << "size of first array after resize = " << firstArray.size() << std::endl;

    for (size_t i = 0; i < newSize; ++i)
    {
        std::cout << "No " << i << " = " << firstArray.get(i) << std::endl;
    }
    std::cout << std::endl;

    // проверка метода изменения размеров массива в сторону уменьшения
    newSize = 8;
    firstArray.resize(newSize);
    std::cout << "size of first array after one more resize = " << firstArray.size() << std::endl;

    for (size_t i = 0; i < newSize; ++i)
    {
        std::cout << "No " << i << " = " << firstArray.get(i) << std::endl;
    }
    std::cout << std::endl;

    // проверка конструктора копирования
    IntArray secondArray(firstArray);
    size_t secondSize = secondArray.size();

    std::cout << "size of second array copied from first = " << secondArray.size() << std::endl;

    for (size_t i = 0; i < secondSize; ++i)
    {
        std::cout << "No " << i << " = " << secondArray.get(i) << std::endl;
    }
    std::cout << std::endl;

    // перезаписываем второй массив для удобства тестирования
    for (size_t i = 0; i < secondSize; ++i)
    {
        secondArray.get(i) = static_cast<int>(secondSize - i);
    }

    // проверка оператора присваивания
    IntArray thirdArray;
    thirdArray = secondArray;
    std::cout << "third array after assignment of second array values:" << std::endl;

    for (size_t i = 0; i < secondSize; ++i)
    {
        std::cout << "No " << i << " = " << thirdArray.get(i) << std::endl;
    }
    std::cout << std::endl;

    // проверка перемещающего конструктора
    IntArray fourthArray(std::move(secondArray));
    std::cout << "fourth array after `moving constructor`" << std::endl;

    for (size_t i = 0; i < secondSize; ++i)
    {
        std::cout << "No " << i << " = " << fourthArray.get(i) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "second array size after `moving constructor` = " << secondArray.size() << std::endl;

    // проверка перемещающего оператора присваивания
    std::cout << "first array size before `move assignment operator` = " << firstArray.size() << std::endl;
    std::cout << std::endl;
    secondArray = std::move(firstArray);
    std::cout << "first array size after `move assignment operator` = " << firstArray.size() << std::endl;
    std::cout << "second array size after `move assignment operator` = " << secondArray.size() << std::endl;

    return 0;
}