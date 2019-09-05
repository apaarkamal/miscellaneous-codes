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


void the_martian() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}

const int N = 100005, M = 20;

int dep[N], timer = 0, tin[N], tout[N], Par[N][M], dist[N];
vector<int> gr[N];

void dfs(int cur, int par) {
    tin[cur] = ++timer;
    Par[cur][0] = par;
    for (int i = 1; i < M; i++) {
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }
    for (auto x : gr[cur]) {
        if (x != par) {
            dep[x] = dep[cur] + 1;
            dist[x] = dep[cur] + 1;
            dfs(x, cur);
        }
    }
    tout[cur] = timer;
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = M - 1; i >= 0; i--) {
        if (!is_ancestor(Par[u][i], v)) {
            u = Par[u][i];
        }
    }
    return Par[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}

void bfs(int u) {
    queue<int> Q;
    Q.push(u);
    dist[u] = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (auto x : gr[cur]) {
            if (dist[x] > dist[cur] + 1) {
                Q.push(x);
                dist[x] = dist[cur] + 1;
            }
        }
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        dfs(1, 0);
        k = sqrt(m);
        int stored[k], z = 0;
        for (i = 0; i < m;) {
            for (j = i; j < i + k && j < m; j++) {
                int t, u;
                cin >> t >> u;
                if (t) {
                    stored[z++] = u;
                }
                else {
                    ans = dist[u];
                    for (int ii = 0; ii < z; ii++) {
                        ans = min(dis(u, stored[ii]), ans);
                    }
                    cout << ans << '\n';
                }
            }
            while (z) {
                bfs(stored[z - 1]);
                z--;
            }
            i = j;
        }
    }
}