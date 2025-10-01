// Given a Prefix expression, convert it into a Postfix expression. 
// Conversion of Prefix expression directly to Postfix without going through the process of converting them first to Infix and then to Postfix is much better in terms of computation and better understanding the expression (Computers evaluate using Postfix expression). 

// let's discuss about Prefix and Postfix notation:

// Prefix: An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2). 
// Example : *+AB-CD (Infix : (A+B) * (C-D) )

// Postfix: An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator). 
// Example : AB+CD-* (Infix : (A+B * (C-D) )

// Examples: 

// Input :  Prefix :  *+AB-CD
// Output : Postfix : AB+CD-*
// Explanation : Prefix to Infix :  (A+B) * (C-D)
//                          Infix to Postfix :  AB+CD-*

// Input :  Prefix :  *-A/BC-/AKL
// Output : Postfix : ABC/-AK/L-*
// Explanation : Prefix to Infix :  (A-(B/C))*((A/K)-L)
//                          Infix to Postfix : ABC/-AK/L-* 


#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(string prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperator(c)) {
            // Pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Concatenate in Postfix order
            string temp = op1 + op2 + c;

            // Push result back to stack
            st.push(temp);
        } else {
            // If operand, push to stack
            st.push(string(1, c));
        }
    }

    // Final element is the postfix expression
    return st.top();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
