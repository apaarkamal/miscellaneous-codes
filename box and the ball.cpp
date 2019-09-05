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
        ll a[m], b[m];
        ll cntt[n + 1] = {}, vis[n + 1] = {};
        memset(cntt, 1, sizeof(cntt));
        for (i = 0; i < m; i++) {
            cin >> a[i] >> b[i];
        }
        for (i = 1; i <= n; i++) {
            cntt[i] = 1;
        }
        vis[1]++;
        for (i = 0; i < m; i++) {
            if (vis[a[i]]) {
                vis[b[i]]++;
                cntt[a[i]]--;
                cntt[b[i]]++;
                // cout<<cntt[a[i]]<<" "<<cntt[b[i]]<<'\n';
                if (cntt[a[i]] == 0) {
                    vis[a[i]] = 0;
                }
            }
            else {
                cntt[a[i]]--;
                cntt[b[i]]++;
            }
        }
        for (i = 1; i <= n; i++) {
            if (vis[i] && cntt[i]) {
                ans++;
            }
        }
        cout << ans;
    }
}