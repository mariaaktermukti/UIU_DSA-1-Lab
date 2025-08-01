// The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones.
//  Formula:
// F(n)=F(n−1)+F(n−2)

// F(0)=0,F(1)=1
// Example:
// Let’s list the first 7 Fibonacci numbers step by step:
// =F(1)+F(0)=1+0=1
// =F(2)+F(1)=1+1=2
// =F(3)+F(2)=2+1=3
// =F(4)+F(3)=3+2=5
// =F(5)+F(4)=5+3=8

// So the sequence is:
// 0, 1, 1, 2, 3, 5, 8, …

#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}
int main()
{
    cout<< fib(10) << endl;
    return 0;
}