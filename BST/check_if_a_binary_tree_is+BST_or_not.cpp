#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Check BST in array representation
bool isBSTArray(const vector<int> &arr, int i, long long minVal, long long maxVal)
{
    if (i >= arr.size() || arr[i] == -1)
        return true;

    if (arr[i] < minVal || arr[i] > maxVal)
        return false;

    return isBSTArray(arr, 2 * i + 1, minVal, arr[i] - 1) &&
           isBSTArray(arr, 2 * i + 2, arr[i] + 1, maxVal);
}

int main()
{
    int n;
    cout << "How many nodes in the tree? ";
    cin >> n;

    vector<int> tree(n);
    cout << "Enter nodes in array form (-1 for NULL): ";
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    if (isBSTArray(tree, 0, LLONG_MIN, LLONG_MAX))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
