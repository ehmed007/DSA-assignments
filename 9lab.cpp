#include "iostream"
#include "fstream"
#include "stack"
using namespace std;

bool delimetersOK(const string& exp) {
    stack<char> st;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '[') {
            st.push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']') {
            if (st.top() == '(' && exp[i] == ')') {
                st.pop();
            }
            else if (st.top() == '[' && exp[i] == ']') {
                st.pop();
            }
        }        
    }
    if (st.empty()) {
        return true;
    }
    return false;
}

int main() {
    fstream newfile;
    newfile.open("input.txt",ios::in);
    string first_line;
    getline(newfile, first_line);
    string line;
    while(!newfile.eof()) {
        getline(newfile,line);
        if (delimetersOK(line)) {
            cout << "VALID" << endl;
        }
        else {
            cout << "INVALID" << endl;
        }
    }
    return 0;
}