#include <iostream>
#include <string>
#include "infix.h"
#include "stack.h"
#include "queue.h"

using namespace std;

bool InfixCalculator::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int InfixCalculator::getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string InfixCalculator::infixToPostfix(const std::string& expression) {
    Stack stack;
    Queue queue;
    std::string postfix;

    int operand = 0; // Временная переменная для построения многозначного числа

    for (char c : expression) {
        if (isdigit(c)) {
            operand = operand * 10 + (c - '0'); // Добавляем цифру к многозначному числу
        } else if (c == ' ') {
            if (operand != 0) {
                postfix += std::to_string(operand) + ' '; // Добавляем многозначное число в постфиксную строку
                operand = 0;
            }
        } else if (c == '(') {
            stack.push('(');
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                queue.enqueue(stack.pop());
            }
            if (!stack.isEmpty() && stack.top() == '(')
                stack.pop();
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                queue.enqueue(stack.pop());
            }
            stack.push(c);
        }
    }

    if (operand != 0) {
        postfix += std::to_string(operand) + ' ';
    }

    while (!stack.isEmpty()) {
        queue.enqueue(stack.pop());
    }

    while (!queue.isEmpty()) {
        postfix += queue.dequeue();
        postfix += ' ';
    }

    return postfix;
}


int InfixCalculator::calculatePostfix(const string& postfix) {
    Stack stack;

    int operand = 0; // Временная переменная для построения многозначного числа

    for (char c : postfix) {
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
        cout << "Error: Invalid expression." << endl;
        return 0;
    }

    return stack.pop();
}

int InfixCalculator::performOperation(char operation, int operand1, int operand2) {
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
bool InfixCalculator::isValidExpression(const string& expression) {
    Stack stack;

    for (char c : expression) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.isEmpty() || stack.top() != '(') {
                return false; // лишняя скобка
            }
            stack.pop();
        }
    }

    return stack.isEmpty();
}