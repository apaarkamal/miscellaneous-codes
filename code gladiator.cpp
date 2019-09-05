#include<bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
    int t; cin >> t; while (t--)
    {
        int i, j, n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (j = 0; j < m; j++) {
            cin >> b[j];
        }
        sort(a, a + n);
        sort(b, b + m);
        reverse(a, a + n);
        int diff[m + 1] = {};
        for (i = 0; i < n; i++) {
            diff[m - a[i]]++;
        }
        for (i = 1; i < m; i++) {
            diff[i] += diff[i - 1];
        }
        bool bl = 1;
        int cnt = 0;
        for (i = 0; i < m; i++) {
            if (diff[i] - cnt > b[i]) {
                bl = 0;
                break;
            }
            cnt += b[i] - diff[i];
        }
        cout << (bl ? "YES" : "NO") << '\n';
    }
}