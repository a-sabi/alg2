#include <iostream>
#include <string>
#include "infix.h"

using namespace std;

int main() {
    std::string expression;
    std::cout << "Enter an infix expression: " << endl;
    std::getline(std::cin, expression);

    InfixCalculator calculator;

    if (!calculator.isValidExpression(expression)) {
        std::cout << "Error: Invalid expression." << std::endl;
        return 0;
    }

    std::string postfix = calculator.infixToPostfix(expression);
    std::cout << "Postfix expression: " << postfix << std::endl;

    if (postfix.back() == ' ') {
        postfix.pop_back();
    }
    int result = calculator.calculatePostfix(postfix);
    std::cout << "Result: " << result << std::endl;

    return 0;
}