#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 300005;

// Here is one of the ways to find edge biconnected components:
// Let's orient all edges to direction that depth first search passed it for the first time.
// Let's find in new directed graph strongly connected components.
// Statement: the strongly connected components in the new graph coincide with the biconnected components in old undirected graph.
// https://codeforces.com/contest/652/problem/E

vector<P> gr[N], gr2[N], gr2r[N], gr3[N];
int vis[N];

void dfs(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x.F] && x.F != par) {
			gr2[cur].pb({x.F, x.S});
			gr2r[x.F].pb({cur, x.S});
		}
		else if (!vis[x.F]) {
			gr2[cur].pb({x.F, x.S});
			gr2r[x.F].pb({cur, x.S});
			dfs(x.F, cur);
		}
	}
}

vector<int> order;
void dfs2(int cur) {
	vis[cur] = 1;
	for (auto x : gr2[cur]) {
		if (!vis[x.F]) dfs2(x.F);
	}
	order.pb(cur);
}

int cmp[N];
void dfs3(int cur, int comp) {
	vis[cur] = 1;
	cmp[cur] = comp;
	for (auto x : gr2r[cur]) {
		if (!vis[x.F]) dfs3(x.F, comp);
	}
}

int art[N];
void dfs4(int cur, int artifact) {
	vis[cur] = 1 + (artifact | art[cur]);
	for (auto x : gr3[cur]) {
		if (!vis[x.F]) dfs4(x.F, (artifact | x.S) || (artifact | art[cur]));
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			gr[x].pb({y, w});
			gr[y].pb({x, w});
		}
		int a, b;
		cin >> a >> b;
		dfs(1, 0);
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= n; i++) {
			if (!vis[i]) dfs2(i);
		}
		memset(vis, 0, sizeof(vis));
		reverse(order.begin(), order.end());
		for (auto x : order) {
			if (!vis[x]) dfs3(x, ++cnt);
		}
		for (i = 1; i <= n; i++) {
			for (auto x : gr[i]) {
				if (cmp[i] != cmp[x.F]) {
					gr3[cmp[i]].pb({cmp[x.F], x.S});
				}
				else {
					art[cmp[i]] |= x.S;
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		dfs4(cmp[a], 0);
		if (vis[cmp[b]] == 2 || (cmp[a] == cmp[b] && art[cmp[a]])) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
}