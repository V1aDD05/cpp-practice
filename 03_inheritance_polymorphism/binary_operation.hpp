// Заголовочный файл защищён от повторного включения при помощи `include guards`.
#ifndef BIN_OP_CLS_HPP
#define BIN_OP_CLS_HPP

#include "expression.hpp"
#include <memory>

class BinaryOperation : public Expression
{
public:
    // конструктор
    BinaryOperation(std::unique_ptr<const Expression> left, char op, std::unique_ptr<const Expression> right)
        : left(std::move(left)), op(op), right(std::move(right))
    {
    }

    // метод, реализующий вычисления выражения
    double evaluate() const
    {
        switch (op)
        {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            return left->evaluate() / right->evaluate();
        default:
            return 0.0;
        }
    }

private:
    std::unique_ptr<const Expression> left;
    std::unique_ptr<const Expression> right;
    char op; // op это один из 4 символов: '+', '-', '*' или '/'
};

#endif