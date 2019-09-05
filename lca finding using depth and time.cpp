#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 100005, M = 22;
int Par[N][M], dep[N], timer = -1, dis[N], tin[N], tout[N];
V<P> gr[N];

void dfs(int cur, int par) {
    Par[cur][0] = par;
    dep[cur] = dep[par] + 1;
    tin[cur] = ++timer;
    for (int i = 1; i < M; i++) {
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }
    for (auto x : gr[cur]) {
        if (par != x.F) {
            dis[x.F] = dis[cur] + x.S;
            dfs(x.F, cur);
        }
    }
    tout[cur] = timer;
}

int lca_using_depth(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int diff = dep[u] - dep[v];
    for (int i = M - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            u = Par[u][i];
        }
    }
    if (u == v) return v;
    for (int i = M - 1; i >= 0; i--) {
        if (Par[u][i] != Par[v][i]) {
            u = Par[u][i];
            v = Par[v][i];
        }
    }
    return Par[u][0];
}

bool is_ancestor(int u, int v) {
    //is u ancestor of v?
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca_using_timeinout(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = M - 1; i >= 0; i--) {
        if (!is_ancestor(Par[u][i], v)) {
            u = Par[u][i];
        }
    }
    return Par[u][0];
}

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
        for (i = 1; i < n; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            gr[x].pb({y, w});
            gr[y].pb({x, w});
        }
        timer = -1;
        tin[0] = -1; tout[0] = n + 1; //0 is the ultimate parent
        dfs(1, 0);
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            int lca = lca_using_depth(u, v);
            cout << dis[u] + dis[v] - 2 * dis[lca] << '\n';
        }
        //clear
        for (i = 0; i <= n; i++) {
            gr[i].clear();
            for (j = 0; j < M; j++) {
                Par[i][j] = 0;
            }
        }
    }
}