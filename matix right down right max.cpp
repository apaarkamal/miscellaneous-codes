#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        ll a[n][m] = {}, b[n][m] = {}, c[n][m] = {};
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            for (j = m - 2; j >= 0; j--) {
                b[i][j] += b[i][j + 1];
            }
        }
        for (i = 1; i < n; i++) {
            for (j = 0; j < m; j++) {
                ans = max(b[i][j] + b[i - 1][j], ans);
                b[i][j] = max(b[i][j], b[i - 1][j] + a[i][j]);
            }
        }
        cout << ans << '\n';
    }
}
