https://www.codechef.com/PILT2019/problems/DIFFSTR?
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

const ll N = 2005;

ll dp[N][405][27];

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
        for (i = 1; i <= n; i++) {
            ll ss; cin >> ss;
            string s; cin >> s;
            for (j = 0; j < ss; j++) {
                for (k = 0; k < 26; k++) {
                    dp[i][j][k] = dp[i - 1][j][k] + abs(s[j] - 'a' - k);
                }
            }
            for (j = ss; j < 405; j++) {
                for (k = 0; k < 26; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
        while (m--) {
            ll l, r;
            cin >> l >> r;
            string s;
            cin >> s;
            ans = 0;
            for (j = 0; j < s.size(); j++) {
                ans += dp[r][j][s[j] - 'a'] - dp[l - 1][j][s[j] - 'a'];
            }
            cout << ans << '\n';
        }

    }
}