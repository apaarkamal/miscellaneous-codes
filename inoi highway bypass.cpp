#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
#define mod 20011ll
const ll N = 310;
ll a[N][N], way[N][N], ans = 0;
ll dp[N][N][2][N];
//dir 0 right 1 down
ll findway(ll x, ll y, ll k, ll n, ll m, ll dir, ll dn, ll rt) {
    ll i, j, z, cnt = 0;
    // cout<<x<<" "<<y<<" "<<ans<<'\n';
    if (x > n || y > m) {
        return 0;
    }
    if (!a[x][y]) {
        return 0;
    }
    if (dn > k || rt > k) {
        return 0;
    }
    if (x == n && y == m) {
        return 1;
    }
    if (dir == 0) {
        if (dp[x][y][dir][rt] != -1) {
            return dp[x][y][dir][rt];
        }
        if (rt < k) {
            cnt += findway(x, y + 1, k, n, m, 0ll, 0ll, rt + 1);
        }
        cnt += findway(x + 1, y, k, n, m, 1ll, 1ll, 0ll);
        return dp[x][y][dir][rt] = cnt % mod;
    }
    else {
        if (dp[x][y][dir][dn] != -1) {
            return dp[x][y][dir][dn];
        }
        if (dn < k) {
            cnt += findway(x + 1, y, k, n, m, 1ll, dn + 1, 0ll);
        }
        cnt += findway(x, y + 1, k, n, m, 0ll, 0ll, 1ll);
        return dp[x][y][dir][dn] = cnt % mod;
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
        cin >> n >> m >> k;
        memset(dp, -1ll, sizeof(dp));
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        cout << findway(1ll, 1ll, k, n, m, 0ll, 0, 0);
    }
}
