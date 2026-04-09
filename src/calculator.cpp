#include "calculator.h"
#include <stdexcept>
#include <cctype>

int Calculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double Calculator::applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

double Calculator::evaluate(const std::string& tokens) {
    std::stack<double> values;
    std::stack<char> ops;

    for (size_t i = 0; i < tokens.length(); i++) {
        if (isspace(tokens[i])) continue;

        // 🔥 NUMBER PARSING (fast)
        if (isdigit(tokens[i]) || tokens[i] == '.') {
            double val = 0;
            double frac = 0.1;
            bool isFraction = false;

            while (i < tokens.length() && (isdigit(tokens[i]) || tokens[i] == '.')) {
                if (tokens[i] == '.') {
                    isFraction = true;
                } else if (!isFraction) {
                    val = val * 10 + (tokens[i] - '0');
                } else {
                    val += (tokens[i] - '0') * frac;
                    frac *= 0.1;
                }
                i++;
            }
            values.push(val);
            i--;
        }

        // 🔥 UNARY MINUS SUPPORT
        else if (tokens[i] == '-' && (i == 0 || tokens[i-1] == '(' || tokens[i-1] == '+' || tokens[i-1] == '-' || tokens[i-1] == '*' || tokens[i-1] == '/')) {
            i++;
            double val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = val * 10 + (tokens[i] - '0');
                i++;
            }
            values.push(-val);
            i--;
        }

        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                if (values.size() < 2)
                    throw std::runtime_error("Invalid expression");

                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyOp(a, b, op));
            }
            if (ops.empty()) throw std::runtime_error("Mismatched brackets");
            ops.pop();
        }

        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                if (values.size() < 2)
                    throw std::runtime_error("Invalid expression");

                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyOp(a, b, op));
            }
            ops.push(tokens[i]);
        }
    }

    while (!ops.empty()) {
        if (values.size() < 2)
            throw std::runtime_error("Invalid expression");

        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        values.push(applyOp(a, b, op));
    }

    if (values.size() != 1)
        throw std::runtime_error("Invalid expression");

    return values.top();
}
