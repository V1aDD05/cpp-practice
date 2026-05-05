// Заголовочный файл защищён от повторного включения при помощи `include guards`.
#ifndef EXPRESSION_CLS_HPP
#define EXPRESSION_CLS_HPP

class Expression
{
public:
    virtual double evaluate() const = 0;

    virtual ~Expression() {}
};

#endif