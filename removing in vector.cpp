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

const ll N = 50005;

// list<ll> *v;
// v = new list<ll>[N];
ll vis[N];
ll n;

void dfs(ll cur) {
    vis[cur]++;
    for (auto x : v[cur]) {
        if (!vis[x]) dfs(x);
    }
}

bool isconnected() {
    for (ll i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    dfs(1);
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) return false;
    }
    return true;
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
        ll i, j, k, s, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m >> s;
        tuple<ll, ll, ll> edges[m];
        for (i = 0; i < m; i++) {
            ll x, y, w;
            cin >> x >> y >> w;
            v[x].pb(y);
            v[y].pb(x);
            edges[i] = make_tuple(w, x, y);
        }
        sort(edges, edges + m);
        for (auto t : edges) {
            ll x = get<1>(t);
            ll y = get<2>(t);
            ll w = get<0>(t);
            v[x].remove(y);
            v[y].remove(x);
            if (isconnected()) {
                if (cnt + w < s) {
                    cnt += w;
                    ans++;
                }
                else {
                    break;
                }
            }
            else {
                v[x].pb(y);
                v[y].pb(x);
            }
        }
        cout << ans << " " << cnt;
    }
}