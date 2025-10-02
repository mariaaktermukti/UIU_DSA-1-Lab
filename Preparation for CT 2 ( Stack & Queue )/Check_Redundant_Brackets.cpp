// Given a balanced expression string s, check if it contains redundant parentheses.
// Return true if redundant, else false.
// Redundant Parentheses: Parentheses are redundant if
// removing them does not change the expression.
// Note: Expression is valid, contains operators +, -, *, /, and no spaces.

// Examples:

// Input: s = "((a+b))"
// Output: true
// Explanation: ((a+b)) can be simplified to (a+b), which means the outer parentheses are redundant.

// Input: s = "(a+(b)/c)"
// Output: true
// Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.

// Input: s = "((a+b)*c)"
// Output:  false
// Explanation: Removing any parentheses would change the order of evaluation, so none of them are redundant.

#include <bits/stdc++.h>
using namespace std;

bool hasRedundantParentheses(const string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == ')')
        {
            bool operatorFound = false;
            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    operatorFound = true;
                }
            }

            if (!st.empty())
                st.pop(); // pop the opening '('

            // if no operator found inside (), it's redundant
            if (!operatorFound)
                return true;
        }
        else
        {
            st.push(c);
        }
    }

    return false;
}

int main()
{
    string s;
    cin >> s;

    if (hasRedundantParentheses(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
