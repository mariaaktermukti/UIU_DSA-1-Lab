#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n],even[n],odd[n];
    int evencount=0,oddcount=0;

    cout<< "array: ";
    for(int i=0;i<n;i++)
    {
        cin>> arr[i];

        if(arr[i]%2 ==0)
        {
            even[evencount++]=arr[i];
        }
        else
        {
            odd[oddcount++]= arr[i];
        }
    }

    for(int i=1;i<evencount;i++)
    {
        int key=even[i];
        int j=i-1;
        while(j>=0 && even[j]> key)
        {
            even[j+1]=even[j];
            j--;
        }
        even[j+1]= key;
    }

    for(int i=1;i<oddcount;i++)
    {
        int key=odd[i];
        int j=i-1;

        while(j>=0 && odd[j]> key)
        {
            odd[j+1]= odd[j];
            j--;
        }
        odd[j+1]= key;
    }


    cout << "Sorted Array: ";
    for(int i=0;i<evencount;i++)
    {
        cout<< even[i]<< " ";
    }
    for(int i=0;i<oddcount;i++)
    {
        cout<< odd[i] << " ";
    }
    cout << endl;

    return 0;
}
