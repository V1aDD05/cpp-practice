#include <iostream>

#include "expression.hpp"
#include "number.hpp"
#include "binary_operation.hpp"

int main()
{
    char plusOperation = '+';
    char minusOperation = '-';
    char mulOperation = '*';
    char divOperation = '/';

    int leftInt = 4;
    int rightInt = 2;
    
    // Проверка конструкторов класса `Number`
    Number leftOperand(leftInt);
    std::cout << "Левый операнд = " << leftOperand.evaluate() << std::endl;

    Number rightOperand(rightInt);
    std::cout << "Правый операнд = " << rightOperand.evaluate() << std::endl;

    // Проверка сложения
    std::unique_ptr<const Expression> leftPlus = std::make_unique<Number>(leftInt);

    std::unique_ptr<const Expression> rightPlus = std::make_unique<Number>(rightInt);

    BinaryOperation plusResult(std::move(leftPlus), plusOperation, std::move(rightPlus));
    std::cout << "result of `+` operation = " << plusResult.evaluate() << std::endl;

    // Проверка вычитания
    std::unique_ptr<const Expression> leftMinus = std::make_unique<Number>(leftInt);

    std::unique_ptr<const Expression> rightMinus = std::make_unique<Number>(rightInt);

    BinaryOperation minusResult(std::move(leftMinus), minusOperation, std::move(rightMinus));
    std::cout << "result of `-` operation = " << minusResult.evaluate() << std::endl;

    // Проверка умножения
    std::unique_ptr<const Expression> leftMul = std::make_unique<Number>(leftInt);

    std::unique_ptr<const Expression> rightMul = std::make_unique<Number>(rightInt);

    BinaryOperation mulResult(std::move(leftMul), mulOperation, std::move(rightMul));
    std::cout << "result of `*` operation = " << mulResult.evaluate() << std::endl;

    // Проверка деления
    std::unique_ptr<const Expression> leftDiv = std::make_unique<Number>(leftInt);

    std::unique_ptr<const Expression> rightDiv = std::make_unique<Number>(rightInt);

    BinaryOperation divResult(std::move(leftDiv), divOperation, std::move(rightDiv));
    std::cout << "result of `/` operation = " << divResult.evaluate() << std::endl;
}