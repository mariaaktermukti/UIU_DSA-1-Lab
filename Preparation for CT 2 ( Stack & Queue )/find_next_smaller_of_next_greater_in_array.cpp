#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int *nge = new int[n]; // index of next greater element, -1 if none
    int *nsr = new int[n]; // index of next smaller to the right, -1 if none
    for (int i = 0; i < n; ++i)
    {
        nge[i] = -1;
        nsr[i] = -1;
    }

    // 1) Compute Next Greater Element indices
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();

    // 2) Compute Next Smaller to the Right indices
    // When we find arr[i] < arr[st.top()], that top's next smaller is i
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            nsr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // 3) For every element, print the "next smaller of next greater"
    for (int i = 0; i < n; ++i)
    {
        if (nge[i] == -1)
        {
            cout << -1;
        }
        else
        {
            int idxGreater = nge[i];
            if (nsr[idxGreater] == -1)
                cout << -1;
            else
                cout << arr[nsr[idxGreater]];
        }
        if (i + 1 < n)
            cout << " ";
    }
    cout << "\n";

    delete[] arr;
    delete[] nge;
    delete[] nsr;
    return 0;
}
