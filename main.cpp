#include <iostream>
#include <string>
#include "infix.h"

using namespace std;

int main() {
    std::string expression;
    std::cout << "Enter an infix expression: " << endl;
    std::getline(std::cin, expression);

    InfixCalculator calculator;
    std::string postfix = calculator.infixToPostfix(expression);

    std::cout << "Postfix expression: " << postfix << std::endl;

    int result = calculator.calculatePostfix(postfix);

    if (calculator.isValidExpression(expression)) {
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cout << "Error: Invalid expression." << std::endl;
    }

    return 0;
}