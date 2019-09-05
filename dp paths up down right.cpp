#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 1005;
int a[N][N], dp[N][N][3];

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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        // for(i=0;i<n;i++){
        //     for(j=0;j<m;j++){
        //         for(k=0;k<2;k++){
        //             dp[i][j][k]=-1e15;
        //         }
        //     }
        // }
        dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = a[0][0];
        for (i = 1; i < n; i++) {
            dp[i][0][2] = dp[i - 1][0][2] + a[i][0];
        }
        for (j = 1; j < m; j++) {
            dp[0][j][0] = dp[0][j - 1][2] + a[0][j];
            for (i = 1; i < n; i++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][2]) + a[i][j];
            }
            dp[n - 1][j][1] = dp[n - 1][j - 1][2] + a[n - 1][j];
            for (i = n - 2; i >= 0; i--) {
                dp[i][j][1] = max(dp[i + 1][j][1], dp[i][j - 1][2]) + a[i][j];
            }
            for (i = 0; i < n; i++) {
                dp[i][j][2] = max(dp[i][j][0], dp[i][j][1]);
                // db(j,dp[n-1][j][1]);
            }
        }
        cout << dp[n - 1][m - 1][2] << '\n';
    }
}