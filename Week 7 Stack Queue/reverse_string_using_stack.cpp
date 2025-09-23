#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    string reversed = "";
    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
