//floyd warshal algo
// minimum dis between every pair of cities
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        ll a[n][n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = 1000000;
                if (i == j) {
                    a[i][j] = 0;
                }
            }
        }
        for (i = 0; i < m; i++) {
            ll x, y, p;
            cin >> x >> y >> p;
            x--; y--;
            a[x][y] = p;
            a[y][x] = p;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (a[j][i] + a[i][k] < a[j][k]) {
                        a[j][k] = a[j][i] + a[i][k];
                    }
                }
            }
        }
        ans = INT_MIN;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                ans = max(ans, a[i][j]);
                //  cout<<a[i][j]<<" ";
            }
        }
        cout << ans;
    }
}
