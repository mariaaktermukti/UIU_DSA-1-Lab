// Postfix to infix conversion involves transforming expressions where operators follow their operands (postfix notation) into standard mathematical expressions with operators placed between operands (infix notation). This conversion improves readability and understanding.

// Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands. 
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands. 
// Examples: 

// Input: abc++
// Output: (a + (b + c))
// Explanation: Infix expression is  (a + (b + c)) for expression abc++

// Input: ab*c+
// Output: ((a*b)+c)
// Explanation: Infix expression is  ((a*b)+c) for expression ab*c+

// Input: abc+*d/
// Output: (((a * (b + c))) / d)
// Explanation: Infix expression is (((a * (b + c)))/d) for expression abc+*d/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isOperator(c)) {
            // Pop two operands
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Form Infix expression with parentheses
            string temp = "(" + op1 + c + op2 + ")";

            // Push back to stack
            st.push(temp);
        } else {
            // Operand
            st.push(string(1, c));
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
