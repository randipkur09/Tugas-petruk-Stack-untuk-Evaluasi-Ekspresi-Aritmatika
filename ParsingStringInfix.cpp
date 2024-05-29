#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isOperator(char a) {
    return (a=='+' || a=='/' || a=='*' || a=='%' || a=='-');
}

bool isParenthesis(char a) {
    return (a=='(' || a==')');
}

int Precedence(char a) {
    if (a=='+' || a=='-') return 1;
    if (a=='/' || a=='*' || a=='%') return 2;
    if (a=='^') return 3;
    return -1;
}

bool isDigit(char a) {
    return (a<='9' && a>='0');
}

vector<string> splitInfixExpression(const string &infix) {
    vector<string> tokens;
    string number = "";
    size_t length = infix.length();
    bool previousWasOperator = true;

    for (size_t i = 0; i < length; ++i) {
        if (isdigit(infix[i])) {
            number += infix[i];
            previousWasOperator = false;
        } else {
            if (!number.empty()) {
                tokens.push_back(number);
                number.clear();
            }
            if (infix[i] == ' ') {
                continue;
            } else if (infix[i] == '-' && (i == 0 || previousWasOperator || infix[i-1] == '(')) {
                if (i + 1 < length && isdigit(infix[i + 1])) {
                    number += '-';
                } else if (i + 1 < length && infix[i + 1] == '(') {
                    tokens.push_back("-1");
                    tokens.push_back("*");
                } else {
                    tokens.push_back(string(1, infix[i]));
                }
            } else if (isOperator(infix[i])) {
                tokens.push_back(string(1, infix[i]));
                previousWasOperator = true;
            } else if (infix[i] == '(' || infix[i] == ')') {
                tokens.push_back(string(1, infix[i]));
                previousWasOperator = (infix[i] == '(');
            } else {
                tokens.push_back(string(1, infix[i]));
                previousWasOperator = false;
            }
        }
    }

    if (!number.empty()) {
        tokens.push_back(number);
    }

    return tokens;
}

void printTokens(const vector<string> &tokens) {
    for (size_t i = 0; i < tokens.size(); ++i) {
        if (i != 0) cout << " ";
        cout << tokens[i];
    }
    cout << endl;
}

int main() {
    string infix;
    getline(cin, infix);

    vector<string> tokens = splitInfixExpression(infix);
    printTokens(tokens);

    return 0;
}
