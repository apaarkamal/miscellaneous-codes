#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    int i, n, j;
    cin >> n;
    cout << 1 << '\n';
    for (i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                cout << i;
            }
            else {
                cout << 0;
            }
        }
        cout << '\n';
    }
}
