// 5: Evaluate Postfix Expression
// You are given a postfix expression consisting of integers and operators `+ - * /`. Evaluate the
// expression and print the result.
// Input Format:
// A single string containing the postfix expression with space-separated tokens.
// Output Format:
// Print the evaluated result as an integer.
// Sample Input:
// 6 3 2 + * 2 /
// Sample Output:
// 15

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;
    int stack[1000];
    int top = -1;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int b = stack[top--];
            int a = stack[top--];
            int res;
            if (token == "+")
                res = a + b;
            else if (token == "-")
                res = a - b;
            else if (token == "*")
                res = a * b;
            else
                res = a / b;
            stack[++top] = res;
        }
        else
        {
            int num = 0;
            for (int i = 0; i < token.size(); i++)
            {
                num = num * 10 + (token[i] - '0');
            }
            stack[++top] = num;
        }
    }

    cout << stack[top] << endl;
    return 0;
}
