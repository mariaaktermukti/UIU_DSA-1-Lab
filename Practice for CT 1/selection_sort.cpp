#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<< "Enter the number od elements of the array : ";
    cin>> n;

    int ar[n];

    for(int i=0;i<n;i++)
    {
        cin>> ar[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int minInd=i;
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]< ar[minInd])
            {
                minInd=j;
            }
        }
        int temp=ar[i];
        ar[i]=ar[minInd];
        ar[minInd]= temp;
    }

    cout<< "After selection sort: ";

    for(int i=0;i<n;i++)
    {
        cout<< ar[i] << " ";
    }


    return 0;
}