#include <iostream>
#include <stack>
#include <string>
using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


int applyOperation(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}


string infixToPostfix(string infix) {
    stack<char> ops;
    string postfix = "";
    
    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(ch);
        }
    }
    
    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }
    
    return postfix;
}


int evaluatePostfix(string postfix) {
    stack<int> values;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            values.push(ch - '0');
        } else {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            values.push(applyOperation(a, b, ch));
        }
    }
    
    return values.top();
}

int main() {
    string infix;
    

    cout << "Enter an infix expression: ";
    cin >> infix;
    

    string postfix = infixToPostfix(infix);
    int result = evaluatePostfix(postfix);
    

    cout << "Result: " << result << endl;
    return 0;
}
