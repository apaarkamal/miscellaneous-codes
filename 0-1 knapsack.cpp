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
        cin >> n >> m;
        ll size[n + 1], value[n + 1];
        for (i = 1; i <= n; i++) {
            cin >> size[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> value[i];
        }
        ll dp[n + 1][m + 1] = {};
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= m; j++) {
                if (j - size[i] >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - size[i]] + value[i]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<'\n';
        // }
        cout << dp[n][m];
    }
}