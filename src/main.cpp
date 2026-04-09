#include <iostream>
#include <string>
#include "calculator.h"

#ifdef _WIN32
#include <io.h>
#define isatty _isatty
#define fileno _fileno
#else
#include <unistd.h>
#endif

int main() {
    Calculator calc;
    std::string input;

    if (isatty(fileno(stdin))) {
        std::cout << "===========================================\n";
        std::cout << "   High-Performance C++ Calculator\n";
        std::cout << "   Type 'exit' to quit\n";
        std::cout << "===========================================\n";
    }

    while (std::getline(std::cin, input)) {
        if (input == "exit") break;
        if (input.empty()) continue;

        if (!input.empty() && input.back() == '=') {
            input.pop_back();
        }

        try {
            double result = calc.evaluate(input);
            std::cout << "Expression: " << input << std::endl;
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Expression: " << input << std::endl;
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
