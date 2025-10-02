#include <iostream>
#include <climits>
using namespace std;

int countSunlit(int arr[], int n)
{
    if (n == 0)
        return 0;

    int cnt = 1;          
    int maxSeen = arr[0]; 

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= maxSeen)
        {
            cnt++;
            maxSeen = arr[i];
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << countSunlit(arr, n) << "\n";
    return 0;
}
