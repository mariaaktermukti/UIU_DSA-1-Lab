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

    sort(ar, ar+n);
    cout<< "Sorted array: ";
     for(int i=0;i<n;i++)
    {
        cout<< ar[i] << " "; 
    }
    cout << endl;

    int target;
    cout<<"Enter the target elements : ";
    cin>> target;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(ar[mid]== target)
        {
            cout<< "Target found at index: " << mid << endl;
            return 0;
        }

        else if(ar[mid]< target)
        {
            low=mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    cout<< "Target not found." << endl;

    return 0;
}

// Best Case-> O(1)
// Worst Case-> O(log n)
// Average Case -> O(log n)