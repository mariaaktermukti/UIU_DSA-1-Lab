#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m;
    cin >> n;

    int nums1[1001] = {0};  
    int num;

    for (int i = 0; i < n; i++) 
    {
        cin >> num;
        nums1[num] = 1;  
    }

    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        cin >> num;
        if (nums1[num] == 1) 
        { 
            cout << num << " ";
            nums1[num] = 0; 
        }
    }
    cout << endl;
    return 0;
}
