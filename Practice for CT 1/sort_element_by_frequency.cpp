#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n; // Read the size of the array
    int arr[n];
    
    // Input array elements
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Step 1: Sort the array
    // Sorting helps to group same numbers together for easy frequency counting
    sort(arr, arr + n);

    // Step 2: Create arrays to store unique numbers and their frequencies
    int unique[n];   // Array to store unique elements
    int freq[n];     // Array to store frequency of each unique element
    int m = 0;       // Counter for number of unique elements

    int i = 0;
    while (i < n) 
    {
        int val = arr[i]; // Current number
        int count = 0;    // Count frequency of current number

        // Count how many times current number appears consecutively
        while (i < n && arr[i] == val) 
        {
            count++;
            i++;
        }

        // Store the number and its frequency
        unique[m] = val;
        freq[m] = count;
        m++; // Move to next unique number
    }

    // Step 3: Sort unique numbers by frequency (descending)
    // If two numbers have the same frequency, sort by number (ascending)
    for (int i = 0; i < m - 1; i++) 
    {
        for (int j = i + 1; j < m; j++) 
        {
            if (freq[i] < freq[j] || (freq[i] == freq[j] && unique[i] > unique[j])) 
            {
                swap(freq[i], freq[j]);       // Swap frequencies
                swap(unique[i], unique[j]);   // Swap corresponding numbers
            }
        }
    }

    // Step 4: Print numbers according to their frequency
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < freq[i]; j++) 
        {
            cout << unique[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
