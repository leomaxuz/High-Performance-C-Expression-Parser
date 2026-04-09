#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>

class Calculator {
public:
    double evaluate(const std::string& expression);

private:
    int precedence(char op);
    double applyOp(double a, double b, char op);
};

#endif
