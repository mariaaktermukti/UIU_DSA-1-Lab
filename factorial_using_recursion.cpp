// The factorial of a number is the product of all positive integers less than or equal to that number.
// It is written using an exclamation mark: n!
// Formula: 
// n!=n×(n−1)×(n−2)×…×2×1
// Example:
// Let’s calculate 5! (read as “5 factorial”)

// 5!=5×4×3×2×1=120
// So, factorial of 5 is 120.

// Special Case:
// 0!=1(by definition)

#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==1) return 1;
    return n * fact(n-1);
}
int main()
{
    cout << fact(5) << endl;
    return 0;
}