#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the array of elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout<<"k = ";
    cin>> k;

    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]> key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= key;
    }
    cout<< k<< "th Smallest Elements: " << arr[k-1] << endl;

    return 0;
}

