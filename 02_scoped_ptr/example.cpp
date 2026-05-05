#include <iostream>
#include <string>
#include <utility>  //std::move
#include "scoped_ptr.hpp"

int main()
{
    ScopedPtr<std::string> firstStrPtr(new std::string("Hello"));

    // проверка оператора `*`
    std::string firstStrOutput = *firstStrPtr;
    std::cout << "first string is " << firstStrOutput << std::endl;

    // проверка оператора `->`
    size_t firstStrSize = firstStrPtr->size();
    std::cout << "first str size = " << firstStrSize << std::endl;   

    // проверка метода `get()`
    std::string* firstStrRawPtr = firstStrPtr.get();
    std::cout << "raw pointer to first string is " << firstStrRawPtr << std::endl;

    // проверка метода `release()`
    ScopedPtr<std::string> secondStrPtr(firstStrPtr.release());
    std::cout << "first `ScopedPtr` meaning after `release()` is " << firstStrPtr.get() << std::endl;
    std::cout << "second `ScopedPtr` meaning after `release()` is " << secondStrPtr.get() << std::endl;
    std::cout << "second `ScopedPtr` data after `release()` is " << *secondStrPtr << std::endl;

    // проверка метода reset
    secondStrPtr.reset(new std::string("World"));
    std::cout << "second `ScopedPtr` meaning after `reset()` is " << secondStrPtr.get() << std::endl;
    std::cout << "second `ScopedPtr` data after `reset()` is " << *secondStrPtr << std::endl;

    // проверка перемещающего конструктора
    ScopedPtr<std::string> thirdStrPtr(std::move(secondStrPtr));
    std::cout << "second `ScopedPtr` meaning after `moving constructor` is " << secondStrPtr.get() << std::endl;
    std::cout << "third ScopedPtr meaning after `moving constructor` is " << thirdStrPtr.get() << std::endl;
    std::cout << "third ScopedPtr data after `moving constructor` is " << *thirdStrPtr << std::endl;

    //проверка перемещающего оператора присваивания
    firstStrPtr = std::move(thirdStrPtr);
    std::cout << "third `ScopedPtr` meaning after `move assignment operator` is " << thirdStrPtr.get() << std::endl;
    std::cout << "first ScopedPtr meaning after `move assignment operator` is " << firstStrPtr.get() << std::endl;
    std::cout << "first ScopedPtr data after `move assignment operator` is " << *firstStrPtr << std::endl;
}