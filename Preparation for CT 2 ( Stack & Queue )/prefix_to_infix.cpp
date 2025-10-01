// Infix : An expression is called the Infix expression if the operator appears in between the operands in the expression. Simply of the form (operand1 operator operand2).
// Example : (A+B) * (C-D)

// Prefix : An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2).
// Example : *+AB-CD (Infix : (A+B) * (C-D) )

// Given a Prefix expression, convert it into a Infix expression.
// Computers usually does the computation in either prefix or postfix (usually postfix). But for humans, its easier to understand an Infix expression rather than a prefix. Hence conversion is need for human understanding.

// Examples:

// Input :  Prefix :  *+AB-CD
// Output : Infix : ((A+B)*(C-D))

// Input :  Prefix :  *-A/BC-/AKL
// Output : Infix : ((A-(B/C))*((A/K)-L))

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToInfix(string prefix)
{
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isOperator(c))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
        else
        {
            st.push(string(1, c));
        }
    }

    return st.top();
}

int main()
{
    string prefix;
    cout << "Enter Prefix expression: ";
    cin >> prefix;

    cout << "Infix expression: " << prefixToInfix(prefix) << endl;
}
