// Given a sorted array of integers, find if there exists a pair of elements that sum up
// to a given target value.
// Input:
// An integer array arr[] of size n sorted in non-decreasing order.
// An integer target representing the desired sum.
// Output:
// Return true if such a pair exists; otherwise, return false.
// Constraints:
// 1 ≤ n ≤ 10^5
// -10^9 ≤ arr[i], target ≤ 10^9
// Example:
// Input: arr[] = {1, 2, 3, 4, 6}, target = 6 Output: true (because 2 + 4 = 6)
// Input: arr[] = {2, 5, 8, 12, 30}, target = 17 Output: true (because 5 + 12 =
// 17)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<< "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout<< "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target sum : ";
    cin>> target;

    int left=0;
    int right= n-1;

    while(left< right)
    {
        int sum= arr[left]+ arr[right];
        if(sum == target)
        {
            cout << "true" << endl;
            return 0;
        }
        else if(sum< target)
        {
            left++;
        }
        else{
            right--;
        }
    }
    cout << "false" << endl;

    return 0;
}