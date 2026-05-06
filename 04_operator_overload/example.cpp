#include <iostream>
#include <sstream>
#include "rational.hpp"

int main()
{
    // проверка ввода и конструктора
    std::istringstream input("2/5");
    Rational firstRational;
    input >> firstRational;

    // проверка вывода
    std::cout << "input is successful, firstrational is " << firstRational << std::endl;

    // геттеры
    std::cout << "numerator is " << firstRational.get_numerator() << std::endl;
    std::cout << "denominator is " << firstRational.get_denominator() << std::endl;

    Rational secondRational(10, 6);
    std::cout << "second rational is " << secondRational << std::endl;

    //Проверка составных операторов
    secondRational *= firstRational;
    std::cout << "second rational after `*= firstRational` is " << secondRational << std::endl;

    secondRational += 2;
    std::cout << "second rational after `+= 2` is " << secondRational << std::endl;

    secondRational -= 1;
    std::cout << "second rational after `-= 1` is " << secondRational << std::endl;

    secondRational /= firstRational;
    std::cout << "second rational after `/= firstRational` is " << secondRational << std::endl;

    //проверка унарных операторов
    Rational thirdRational = -secondRational;
    std::cout << "third rational after `-secondRational` is " << thirdRational << std::endl;

    firstRational = +secondRational;
    std::cout << "first rational after `+secondRational` is " << firstRational << std::endl;

    //проверка бинарных операторов
    Rational fourthRational = secondRational + 3;
    std::cout << "fourth rational after `secondRational + 3` is " << fourthRational << std::endl;

    firstRational = fourthRational - 1;
    std::cout << "first rational after `fourthRational - 1` is " << firstRational << std::endl;

    secondRational = secondRational * 2;
    std::cout << "second rational after `secondRational * 2` is " << secondRational << std::endl;

    thirdRational = secondRational / firstRational;
    std::cout << "third rational after `secondRational / firstRational` is " << thirdRational << std::endl;

    //проверка операторов сравнения
    std::cout << "is second rational == third rational? " << (secondRational == thirdRational) << std::endl;
    std::cout << "is second rational != third rational? " << (secondRational != thirdRational) << std::endl;
    std::cout << "is second rational < third rational? " << (secondRational < thirdRational) << std::endl;
    std::cout << "is second rational <= third rational? " << (secondRational <= thirdRational) << std::endl;
    std::cout << "is second rational > third rational? " << (secondRational > thirdRational) << std::endl;
    std::cout << "is second rational >= third rational? " << (secondRational >= thirdRational) << std::endl;
}
