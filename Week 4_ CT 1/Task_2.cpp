#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << " x= ";
    cin>> x;

    int l=0,h=n-1;
    int ans =-1;

    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==x)
        {
            ans=mid;
            h=mid-1;
        }
        else if(arr[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }

    }

    cout << "Index: " << ans << endl;

    return 0;
}

