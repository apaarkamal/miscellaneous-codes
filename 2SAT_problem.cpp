// Author : Apaar
// Built  : 25-10-2019 00:48:00
// https://codeforces.com/contest/776/problem/D

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

const int N = 200005;

struct dsu {
	vector<int> p, sz;
	void init(int NN) {
		sz.clear(); p.clear();
		p.resize(NN); sz.resize(NN, 1);
		iota(p.begin(), p.end(), 0);
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
		}
	}
} G;

vector<int> D[N];
int a[N];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		G.init(N);
		for (i = 0; i < n; i++) {
			cin >> a[i];
			a[i] ^= 1;
		}
		for (i = 0; i < m; i++) {
			cin >> k;
			while (k--) {
				int x;
				cin >> x;
				x--;
				D[x].pb(i);
			}
		}
		for (i = 0; i < n; i++) {
			int u = D[i][0], v = D[i][1];
			G.unite(2 * u, (2 * v) ^ a[i]);
			G.unite(2 * u + 1, (2 * v + 1) ^ a[i]);
		}
		for (i = 0; i < m; i++) {
			if (G.get(2 * i) == G.get(2 * i + 1)) return puts("NO"), 0;
		}
		puts("YES");
	}
}