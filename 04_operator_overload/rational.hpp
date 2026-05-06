// Заголовочный файл защищён от повторного включения при помощи `include
// guards`.
#ifndef RATIONAL_CLS_HPP
#define RATIONAL_CLS_HPP

#include <iostream>
#include <numeric>  //std::gcd
#include <cassert>  //assert для обработки деления на ноль

class Rational {
   public:
    // конструктор
    Rational(int numerator = 0, int denominator = 1)
        : numerator_(numerator), denominator_(denominator) 
    {
        //проверка деления на ноль
        assert(denominator_ != 0 && "denominator cannot be zero");
        // приводим дробь к простейшему виду,
        // убираем минус из знаменателя (при наличии)
        normalize();
    }

    // Геттеры
    int get_numerator() const { return numerator_; }
    int get_denominator() const { return denominator_; }

    // Составные операторы
    Rational& operator+=(Rational second_operand);
    Rational& operator-=(Rational second_operand);
    Rational& operator*=(Rational second_operand);
    Rational& operator/=(Rational second_operand);

    // Унарные операторы
    Rational operator+() const { return *this; }
    Rational operator-() const { return Rational(-numerator_, denominator_); }

    // Преобразование в `double`
    //  Потенциальная потеря точности!
    double to_double() const {
        return static_cast<double>(numerator_) / denominator_;
    }

   private:
    int numerator_;
    int denominator_;

    void normalize() {
        // переносим минус в числитель
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        // приводим дробь к простейшему виду
        int gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
};

// Реализация составных операторов
Rational& Rational::operator+=(Rational second_operand){
    numerator_ = numerator_ * second_operand.denominator_ + second_operand.numerator_ * denominator_;
    denominator_ = denominator_ * second_operand.denominator_;
    normalize();
    return *this;
}

Rational& Rational::operator-=(Rational second_operand) {
    numerator_ = numerator_ * second_operand.denominator_ - second_operand.numerator_ * denominator_;
    denominator_ = denominator_ * second_operand.denominator_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(Rational second_operand) {
    numerator_ = numerator_ * second_operand.numerator_;
    denominator_ = denominator_ * second_operand.denominator_;
    normalize();
    return *this;
}

Rational& Rational::operator/=(Rational second_operand) {
    // проверка деления на ноль
    assert(second_operand.numerator_ != 0 && "division by zero");
    numerator_ = numerator_ * second_operand.denominator_;
    denominator_ = denominator_ * second_operand.numerator_;
    normalize();
    return *this;
}

//***
// СВОБОДНЫЕ ФУНКЦИИ, ИСПОЛЬЗУЮЩИЕ ИНТЕРФЕЙСЫ КЛАССА
//***

// Бинарные операторы (реализация через составные)
Rational operator+(Rational left_operand, const Rational& right_operand) {
    return left_operand += right_operand;
}

Rational operator-(Rational left_operand, const Rational& right_operand) {
    return left_operand -= right_operand;
}

Rational operator*(Rational left_operand, const Rational& right_operand) {
    return left_operand *= right_operand;
}

Rational operator/(Rational left_operand, const Rational& right_operand) {
    return left_operand /= right_operand;
}

// Операторы сравнения (используем геттеры)

inline int compare(const Rational& left_operand,
                   const Rational& right_operand) {
    return left_operand.get_numerator() * right_operand.get_denominator() -
           right_operand.get_numerator() * left_operand.get_denominator();
}

bool operator==(const Rational& left_operand, const Rational& right_operand) {
    return compare(left_operand, right_operand) == 0;
}
bool operator!=(const Rational& left_operand, const Rational& right_operand) {
    return compare(left_operand, right_operand) != 0;
}
bool operator>(const Rational& left_operand, const Rational& right_operand) {
    return compare(left_operand, right_operand) > 0;
}
bool operator>=(const Rational& left_operand, const Rational& right_operand) {
    return compare(left_operand, right_operand) >= 0;
}
bool operator<(const Rational& left_operand, const Rational& right_operand) {
    return compare(left_operand, right_operand) < 0;
}
bool operator<=(const Rational& left_operand, const Rational& right_operand) {
    return compare(left_operand, right_operand) <= 0;
}

// Ввод/вывод
std::ostream& operator<<(std::ostream& os, const Rational& r) 
{
    return os << r.get_numerator() << '/' << r.get_denominator();
}
std::istream& operator>>(std::istream& is, Rational& r) 
{ 
    int n, d;
    char slash;
    if (is >> n >> slash >> d && slash == '/')
    {
        r = Rational(n, d);
    }
    //случаи некорректного ввода пока что не обрабатываются
    return is;
}

#endif