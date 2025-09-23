#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cout << "Enter the expression: ";
    cin >> s;

    stack<char> st;
    bool balanced = true;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                balanced = false;
                break;
            }

            if ((ch == ')' && st.top() != '(') ||
                (ch == '}' && st.top() != '{') ||
                (ch == ']' && st.top() != '['))
            {
                balanced = false;
                break;
            }

            st.pop();
        }
    }

    if (!st.empty())
        balanced = false;

    if (balanced)
        cout << "The expression is balanced\n";
    else
        cout << "The expression is NOT balanced\n";

    return 0;
}
