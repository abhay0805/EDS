#include<iostream>
using namespace std;

class CharStack {
public:
    char stack[100];
    int top = -1;

    void Push(char val) {
        stack[++top] = val;
    }

    void Pop() {
        if (top > -1) {
            top--;
        } else {
            cout << "Stack Underflow! Cannot pop." << endl;
        }
    }

    char Peek() {
        if (top > -1) return stack[top];
        cout << "Stack is empty" << endl;
        return '\0';
    }

    bool Underflow() {
        return top == -1;
    }
};

class StringStack {
public:
    string stack[100];
    int top = -1;

    void Push(string val) {
        stack[++top] = val;
    }

    void Pop() {
        if (top > -1) top--;
    }

    string Peek() {
        if (top > -1) return stack[top];
        cout << "Stack is empty" << endl;
        return "";
    }

    bool Underflow() {
        return top == -1;
    }
};

class IntStack {
public:
    int stack[100];
    int top = -1;

    void Push(int val) {
        stack[++top] = val;
    }

    void Pop() {
        if (top > -1) top--;
    }

    int Peek() {
        if (top > -1) return stack[top];
        cout << "Stack is empty" << endl;
        return -1;
    }

    bool Underflow() {
        return top == -1;
    }
};

// Utility functions
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool isAlphaNum(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Prefix to Infix Conversion
string prefix_to_infix(string str) {
    StringStack s;
    int n = 0;
    while (str[n] != '\0') n++;

    for (int i = n - 1; i >= 0; i--) {
        char current_char = str[i];
        if (isAlphaNum(current_char)) {
            string op(1, current_char);
            s.Push(op);
        } else if (isOperator(current_char)) {
            if (s.top < 1) return "Error: Invalid prefix expression";

            string op1 = s.Peek(); s.Pop();
            string op2 = s.Peek(); s.Pop();

            string res = "(" + op1 + current_char + op2 + ")";
            s.Push(res);
        }
    }

    if (s.top == 0) return s.Peek();
    return "Error: Invalid prefix expression";
}

// Infix to Postfix Conversion
string infix_to_postfix(string str) {
    CharStack s;
    string result = "";

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (isAlphaNum(ch)) {
            result += ch;
        } else if (ch == '(') {
            s.Push(ch);
        } else if (ch == ')') {
            while (!s.Underflow() && s.Peek() != '(') {
                result += s.Peek();
                s.Pop();
            }
            if (!s.Underflow() && s.Peek() == '(') {
                s.Pop();
            }
        } else {
            while (!s.Underflow() && precedence(s.Peek()) >= precedence(ch)) {
                if (s.Peek() == '^' && ch == '^') break;
                result += s.Peek();
                s.Pop();
            }
            s.Push(ch);
        }
    }

    while (!s.Underflow()) {
        result += s.Peek();
        s.Pop();
    }

    return result;
}

// Postfix Evaluation
int postfix_evaluation(string str) {
    IntStack s;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (isDigit(ch)) {
            s.Push(ch - '0');  // Convert char to int
        } else if (isOperator(ch)) {
            if (s.top < 1) {
                cout << "Error: Not enough operands in postfix expression." << endl;
                return -1;
            }

            int op2 = s.Peek(); s.Pop();
            int op1 = s.Peek(); s.Pop();
            int res = 0;

            if (ch == '+') res = op1 + op2;
            else if (ch == '-') res = op1 - op2;
            else if (ch == '*') res = op1 * op2;
            else if (ch == '/') {
                if (op2 == 0) {
                    cout << "Error: Division by zero." << endl;
                    return -1;
                }
                res = op1 / op2;
            }

            s.Push(res);
        }
    }

    if (s.top != 0) {
        cout << "Error: Invalid postfix expression." << endl;
        return -1;
    }

    return s.Peek();
}

// Main Program
int main() {
    int choice;
    int exit_flag = 0;

    do {
        cout << "____________Menu_______________" << endl;
        cout << "1. Convert Prefix to Infix" << endl;
        cout << "2. Convert Infix to Postfix" << endl;
        cout << "3. Evaluate Postfix Expression" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string expr;

        switch (choice) {
            case 1:
                cout << "Enter the prefix expression: ";
                cin >> expr;
                cout << "Infix: " << prefix_to_infix(expr) << endl;
                break;
            case 2:
                cout << "Enter the infix expression: ";
                cin >> expr;
                cout << "Postfix: " << infix_to_postfix(expr) << endl;
                break;
            case 3:
                cout << "Enter the postfix expression (operands should be digits only): ";
                cin >> expr;
                cout << "Evaluation Result: " << postfix_evaluation(expr) << endl;
                break;
            case 4:
                exit_flag = 1;
                cout << "Program Ended." << endl;
                break;
            default:
                cout << "Enter a valid choice." << endl;
        }

    } while (!exit_flag);

    return 0;
}

