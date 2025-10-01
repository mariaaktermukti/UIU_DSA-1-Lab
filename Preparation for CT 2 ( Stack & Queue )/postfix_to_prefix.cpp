// Postfix: An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator).
// Example : AB+CD-* (Infix : (A+B) * (C-D) )

// Prefix : An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2).
// Example : *+AB-CD (Infix : (A+B) * (C-D) )

// Problem Statement
// Given a Postfix expression, convert it into a Prefix expression.

// Instead of converting Postfix → Infix → Prefix, we can directly convert Postfix → Prefix.
// This method is both efficient (fewer steps) and intuitive, since computers naturally evaluate expressions in Postfix form.

// Examples:

// Input :  Postfix : AB+CD-*
// Output : Prefix :  *+AB-CD
// Explanation : Postfix to Infix : (A+B) * (C-D)
//               Infix to Prefix :  *+AB-CD

// Input :  Postfix : ABC/-AK/L-*
// Output : Prefix :  *-A/BC-/AKL
// Explanation : Postfix to Infix : ((A-(B/C))*((A/K)-L))
//               Infix to Prefix :  *-A/BC-/AKL

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToPrefix(string postfix)
{
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (isOperator(c))
        {
            // Pop two operands
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            // Concatenate in Prefix order
            string temp = c + op1 + op2;

            // Push back to stack
            st.push(temp);
        }
        else
        {
            // Operand
            st.push(string(1, c));
        }
    }

    // Final element is the Prefix expression
    return st.top();
}

int main()
{
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
