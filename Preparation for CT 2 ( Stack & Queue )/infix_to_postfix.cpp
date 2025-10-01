// Given a string s representing an infix expression ("operand1 operator operand2" ), Convert it into its postfix notation ("operand1 operand2 operator").

// Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

// Examples:

// Input: s = "a*(b+c)/d"
// Output: abc+*d/
// Explanation: The expression is a * (b + c) / d. First, inside the brackets, b + c becomes bc+. Now the expression looks like a * (bc+) / d. Next, multiply a with (bc+), so it becomes abc+* . Finally, divide this result by d, so it becomes abc+*d/.

// Input: s = "a+b*c+d"
// Output: abc*+d+
// Explanation: The expression a + b * c + d is converted by first doing b * c → bc*, then adding a → abc*+, and finally adding d → abc*+d+.

#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isRightAssociative(char op)
{
    return op == '^';
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result = "";

    for (char c : s)
    {
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && st.top() != '(' &&
                   ((precedence(c) < precedence(st.top())) ||
                    (precedence(c) == precedence(st.top()) && !isRightAssociative(c))))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    string postfix = infixToPostfix(s);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
