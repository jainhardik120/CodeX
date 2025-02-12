#include <iostream>
#include <cstring>
#include <cctype>

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() : top(-1) {}

    void push(char c) {
        if (top >= (MAX - 1)) {
            std::cerr << "Stack overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top < 0) {
            std::cerr << "Stack underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top < 0) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(const char* infix) {
    Stack stack;
    int len = strlen(infix);
    for (int i = 0; i < len; ++i) {
        char ch = infix[i];
        if (isalnum(ch)) {
            std::cout << ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                std::cout << stack.pop();
            }
            stack.pop(); // Remove '('
        } else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                std::cout << stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.isEmpty()) {
        std::cout << stack.pop();
    }
    std::cout << std::endl;
}

void infixToPrefix(const char* infix) {
    int len = strlen(infix);
    char reversed[MAX];
    Stack stack;

    // Reverse infix expression and replace parentheses
    for (int i = 0; i < len; ++i) {
        if (infix[i] == '(') reversed[len - i - 1] = ')';
        else if (infix[i] == ')') reversed[len - i - 1] = '(';
        else reversed[len - i - 1] = infix[i];
    }
    reversed[len] = '\0';

    // Convert reversed infix to postfix
    Stack postfixStack;
    for (int i = 0; i < len; ++i) {
        char ch = reversed[i];
        if (isalnum(ch)) {
            postfixStack.push(ch);
        } else if (ch == '(') {
            postfixStack.push(ch);
        } else if (ch == ')') {
            while (!postfixStack.isEmpty() && postfixStack.peek() != '(') {
                std::cout << postfixStack.pop();
            }
            postfixStack.pop(); // Remove '('
        } else {
            while (!postfixStack.isEmpty() && precedence(postfixStack.peek()) > precedence(ch)) {
                std::cout << postfixStack.pop();
            }
            postfixStack.push(ch);
        }
    }
    while (!postfixStack.isEmpty()) {
        std::cout << postfixStack.pop();
    }
    std::cout << std::endl;
}

int main() {
    const char* infix = "a+b*(c^d-e)^(f+g*h)-i";
    std::cout << "Postfix: ";
    infixToPostfix(infix);
    std::cout << "Prefix: ";
    infixToPrefix(infix);
    return 0;
}
