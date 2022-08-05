#include "iostream"
#include "stack"
using namespace std;

void infix_to_postfix(string exp) {
    stack <char> s;
    cout << "Postfix : ";
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ||  exp[i] == '(' || exp[i] == ')') {
            if (exp[i] == '+' || exp[i] == '-') {
                if (s.empty() || s.top() == '(') {
                    s.push(exp[i]);
                } 
                else {
                    cout << s.top();
                    s.pop();
                    s.push(exp[i]);
                }
            }
            if (exp[i] == '*' || exp[i] == '/') {
                if (s.empty()) {
                    s.push(exp[i]);
                } 
                else {
                    if (s.top() == '+' || s.top() == '-') {
                        s.push(exp[i]);
                    } 
                    if (s.top() == '*' || s.top() == '/') {
                        cout << s.top();
                        s.pop();
                        s.push(exp[i]);
                    }
                }
            }
            if (exp[i] == '(' || exp[i] == ')') {
                if (exp[i] == '(') {
                    s.push(exp[i]);
                }
                else {
                    while(s.top() != '(') {
                        cout << s.top();
                        s.pop();
                    }
                }
            }
        }
        else if (exp[i] == ' ') {

        }
        else {
            cout << exp[i];
        }
    }
    while(!s.empty()) {
        if (s.top() != '(') {
            cout << s.top();
        }
        s.pop();
    }
}

int main() {
    string exp = "(a * (b + (c - d)))";
    cout << "Infix   : " << exp << endl;
    infix_to_postfix(exp);
    return 0;
}