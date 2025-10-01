// // Given a string s representing an infix expression ("operand1 operator operand2" ), 
// Convert it into its prefix notation ("operator operand1 operand2").

// // Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left,
//  (* and /) come next with left to right associativity, 
//  and (+ and -) have the lowest precedence with left to right associativity.

// // Examples: 

// // Input: s = "a*(b+c)/d"
// // Output: /*a+bcd 
// // Explanation: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc.
//  Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc),
//   so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.

#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to return precedence
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Infix to Prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    
    // Swap '(' with ')'
    for(int i = 0; i < infix.length(); i++) {
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }
    
    stack<char> st;
    string prefix = "";
    
    for(char c : infix) {
        if(isalnum(c)) {
            // Operand goes directly
            prefix += c;
        } 
        else if(c == '(') {
            st.push(c);
        } 
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        } 
        else if(isOperator(c)) {
            while(!st.empty() && 
                  ((precedence(c) < precedence(st.top())) || 
                   (precedence(c) == precedence(st.top()) && c != '^')) &&
                  st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    // Pop remaining operators
    while(!st.empty()) {
        prefix += st.top();
        st.pop();
    }
    
    reverse(prefix.begin(), prefix.end()); // Reverse to get Prefix
    return prefix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    
    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
    
    return 0;
}
