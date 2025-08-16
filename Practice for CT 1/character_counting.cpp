#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cout << t[i] << endl;
            return 0;
        }
    }
    cout << t[n] << endl;
    return 0;
}
