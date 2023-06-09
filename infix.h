#ifndef ALG_INFIX_H
#define ALG_INFIX_H
#include <string>

class InfixCalculator {
private:
    bool isOperator(char c);
    int getPrecedence(char op);
    int performOperation(char operation, int operand1, int operand2);

public:
    std::string infixToPostfix(const std::string& expression);
    int calculatePostfix(const std::string& postfix);
    bool isValidExpression(const std::string& expression);
};
#endif //ALG_INFIX_H
