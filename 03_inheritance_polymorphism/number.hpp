// Заголовочный файл защищён от повторного включения при помощи `include guards`.
#ifndef NUMBER_CLS_HPP
#define NUMBER_CLS_HPP

#include "expression.hpp"

class Number : public Expression
{
public:
    // конструктор
    Number(double value) : value_(value) {}

    // метод, возвращающий значение числа
    double evaluate() const { return value_; }

private:
    double value_;
};

#endif