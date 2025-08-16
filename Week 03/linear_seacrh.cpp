#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<< "Enter the size of array: ";
    cin>> n;
    int ar[n];

    for(int i=0;i<n;i++)
    {
        cin>> ar[i]; 
    }

    int target;
    cout<< "Enter the target number : " << endl;
    cin>> target;

    for(int i=0;i<n;i++)
    {
        if(ar[i]== target)
        {
            cout << "Found-> at index : " << i << endl;
            return 0;
        }
    }
     cout<<"Not found" << endl;
}

// Best Case: O(1)
// Worst Case: O(n)
// Average Case: O(n)
