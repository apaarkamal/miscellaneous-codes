//https://codeforces.com/contest/1084/problem/D
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 300005;
vector<pair<ll, ll>> v[N];
ll vis[N], dp[N];
ll a[N], ans = 0;
void dfs(ll cur) {
    vis[cur]++;
    dp[cur] = a[cur];
    ans = max(ans, dp[cur]);
    for (auto x : v[cur]) {
        if (!vis[x.first]) {
            dfs(x.first);
            ans = max(ans, dp[cur] + max(dp[x.first] - x.second, 0ll));
            dp[cur] = max(dp[cur], a[cur] + max(dp[x.first] - x.second, 0ll));
        }
    }
}
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
        ll i, j, k, n, m, cnt = 0, sum = 0;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        for (i = 1; i < n; i++) {
            ll x, y, w;
            cin >> x >> y >> w;
            v[x].push_back({y, w});
            v[y].push_back({x, w});
        }
        dfs(1ll);
        cout << ans;
    }
}