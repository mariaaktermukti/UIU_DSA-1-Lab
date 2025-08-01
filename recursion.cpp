#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if(n> 5) return;
    cout<< n<< endl;
    rec(n+1);
}

int main()
{
    rec(1);
    return 0;
}