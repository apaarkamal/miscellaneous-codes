// https://hack.codingblocks.com/contests/c/547/928
// colorful knapsack
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const ll N = 100005;

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
        cin >> j >> n >> m;
        ll dp[105][10005] = {};
        vector<ll> v[105];
        ll a[105];
        for (i = 0; i < j; i++) {
            cin >> a[i];
        }
        for (i = 0; i < j; i++) {
            ll x; cin >> x;
            v[x].pb(a[i]);
        }
        for (auto x : v[1]) {
            dp[1][x]++;
        }
        for (i = 1; i < n; i++) {
            for (j = 0; j <= m; j++) {
                if (dp[i][j]) {
                    for (auto x : v[i + 1]) {
                        if (j + x <= m) {
                            dp[i + 1][j + x]++;
                        }
                    }
                }
            }
        }
        for (j = 1; j <= m; j++) {
            if (dp[n][j]) {
                ans = max(ans, j);
            }
        }
        if (ans == 0) cout << -1;
        else cout << m - ans;
    }
}