#include "postfix.h"
#include <iostream>
using namespace std;

int Calculator::calculatePostfix(const string& expression) {
    Stack stack;
    int operand = 0; // Временная переменная для построения многозначного числа

    for (char c : expression) {
        if (isdigit(c)) {
            operand = operand * 10 + (c - '0'); // Добавляем цифру к многозначному числу
        } else if (c == ' ') {
            stack.push(operand); // Добавляем многозначное число в стек
            operand = 0;
        } else if (isOperator(c)) {
            if (stack.isEmpty()) {
                cout << "Error: Invalid expression." << endl;
                return 0;
            }
            int operand2 = stack.pop();
            if (stack.isEmpty()) {
                cout << "Error: Invalid expression." << endl;
                return 0;
            }
            int operand1 = stack.pop();
            int result = performOperation(c, operand1, operand2);
            stack.push(result);
        }
    }

    if (stack.isEmpty()) {
        std::cout << "Error: Invalid expression." << std::endl;
        return 0;
    }

    return stack.pop();
}

bool Calculator::isOperator(char c) { // проверяет, является ли символ оператором.
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int Calculator::performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else {
                cout << "Error: Div by zero." << endl;
                return 0;
            }
        default:
            return 0;
    }
}