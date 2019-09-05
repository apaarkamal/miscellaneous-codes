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

const ll N = 1005;
const ll mod = 1000000021;

vector<ll> v[N], vr[N], ccp[N], g[N], gr[N], ccpval[N];
ll vis[N], cnt = 0, b[N], mark[N], val, dp[N];
stack<ll> St;
queue<ll> Q[N];

void dfs(ll cur) {
    vis[cur]++;
    for (auto x : v[cur]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
    St.push(cur);
}

void dfs2(ll cur) {
    vis[cur]++; mark[cur] = cnt;
    ccp[cnt].pb(cur); ccpval[cnt].pb(b[cur]);
    for (auto x : vr[cur]) {
        if (!vis[x]) {
            dfs2(x);
        }
    }
}

void dfs3(ll cur) {
    vis[cur]++;
    for (auto x : g[cur]) {
        if (!vis[x]) {
            dfs3(x);
        }
    }
    val += ccpval[cur][0] * ccp[cur].size();
    return ;
}

void dfs4(ll cur, ll cmp) {
    Q[cmp].push(cur);
    while (!Q[cmp].empty()) {
        ll to = Q[cmp].front(); Q[cmp].pop();
        if (vis[to]) continue;
        vis[to]++;
        for (auto x : v[to]) {
            if (mark[x] == cmp) {
                Q[cmp].push(x);
            }
            else {
                g[cmp].pb(mark[x]);
                dfs4(x, mark[x]);
            }
        }
    }
    return ;
}

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
        ll i, j, k, n, m, ans = 0, sum = 0;
        cin >> n >> m >> k;
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (i = 0; i < N; i++) {
            v[i].clear();
            vr[i].clear();
            ccp[i].clear();
            g[i].clear();
            gr[i].clear();
            ccpval[i].clear();
            mark[i] = -1;
            vis[i] = 0;
            dp[i] = -1;
            while (!Q[i].empty()) {
                Q[i].pop();
            }
        }
        while (!St.empty()) {
            St.pop();
        }
        while (m--) {
            ll x, y;
            cin >> x >> y;
            v[x].pb(y);
            vr[y].pb(x);
        }
        for (i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        while (!St.empty()) {
            ll cur = St.top(); St.pop();
            if (vis[cur]) continue;
            dfs2(cur);
            cnt++;
        }
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < cnt; i++) {
            if (!vis[ccp[i][0]]) {
                dfs4(ccp[i][0], i);
            }
        }

        // for(i=0;i<cnt;i++){
        //     cout<<i<<" ";
        //     for(auto x:g[i]){
        //         cout<<x<<" ";
        //     }cout<<'\n';
        // }

        for (i = 0; i < cnt; i++) {
            sort(ccpval[i].begin(), ccpval[i].end());
            ans += ccpval[i][0] * ccp[i].size();
        }

        // memset(vis,0,sizeof(vis));
        // for(i=0;i<cnt;i++){
        //     for(j=0;j<=1000;j++){
        //         vis[j]=0;
        //     }
        //     val=0;
        //     dfs3(i);
        //     ans=max(ans,val);
        // }

        cout << ans % mod << '\n';
    }
}