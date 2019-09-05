#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    string s;
    cin >> s;
    int sz, n = s.size(), start;
    for (sz = 1; sz <= n; sz++) {
        for (start = 0; start + sz <= n; start++) {
            int k = sz, z = start;
            while (k--) {
                cout << s[z];
                z++;
            }
            cout << '\n';
        }
    }
}
