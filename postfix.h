#ifndef ALG_POSTFIX_H
#define ALG_POSTFIX_H
#include <string>
#include "stack.h"
using namespace std;

class Calculator {
private:
    bool isOperator(char c);
    int performOperation(char operation, int operand1, int operand2);

public:
    int calculatePostfix(const string& expression);
};

#endif //ALG_POSTFIX_H
