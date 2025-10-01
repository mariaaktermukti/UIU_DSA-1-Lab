#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char stack[1000];
    int top = -1;

    bool balanced = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            top++;
            stack[top] = '(';
        }
        else if (s[i] == ')')
        {
            if (top == -1)
            {
                balanced = false;
                break;
            }
            else
            {
                top--;
            }
        }
    }

    if (top != -1)
        balanced = false;

    if (balanced)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
