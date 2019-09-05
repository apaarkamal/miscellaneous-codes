// https://ide.codingblocks.com/s/97573
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        ll a[n + 1];
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        ll dp[n + 1] = {};
        for (i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + a[i];
            dp[i] %= n;
            dp[i] += n; dp[i] %= n;
        }
        ll zero = 0;
        map<ll, ll> mp;
        for (i = 0; i <= n; i++) {
            mp[dp[i]]++;
        }
        for (auto x : mp) {
            ans += ((x.second) * (x.S - 1)) / 2;
        }
        cout << ans << '\n';
    }
}