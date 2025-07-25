#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int ar[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                int temp= ar[j];
                ar[j]= ar[j+1];
                ar[j+1]= temp;
            }
        }
    }
}

void PrintArray(int ar[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<< ar[i] << " ";
    }
    cout<< endl;
}

int main()
{
    int n;
    cout << "Enter the elements: ";
    cin>> n;
    int ar[n];

    cout<< "Enter " << n << " Elements\n";
    for(int i=0;i<n;i++)
    {
        cin>> ar[i];
    }

    cout<< "Before sorting : ";
    PrintArray(ar, n);

    BubbleSort(ar, n);

    cout<< "After sorting : ";
    PrintArray(ar, n);


    return 0;
}