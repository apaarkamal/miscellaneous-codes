// Author : Apaar
// Built  : 29-10-2019 14:44:39
// https://codeforces.com/contest/600/problem/E
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

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const int N = 100005;

vector<int> gr[N];
map<int, int> mp[N];
int res[N], id[N], mx_freq[N], a[N], sum[N];

void nice_merge(int x, int y) {
	// merge y in x
	if (mp[id[x]].size() < mp[id[y]].size()) {
		swap(id[x], id[y]);
	}
	for (auto it : mp[id[y]]) {
		mp[id[x]][it.F] += it.S;
		if (mx_freq[id[x]] < mp[id[x]][it.F]) {
			mx_freq[id[x]] = mp[id[x]][it.F];
			sum[id[x]] = 0;
		}
		if (mx_freq[id[x]] == mp[id[x]][it.F]) {
			sum[id[x]] += it.F;
		}
	}
}

void dfs(int cur, int par) {
	mp[id[cur]][a[cur]] = 1;
	sum[id[cur]] = a[cur];
	mx_freq[id[cur]] = 1;
	for (auto x : gr[cur]) if (x != par) {
			dfs(x, cur);
			nice_merge(cur, x);
		}
	res[cur] = sum[id[cur]];
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i + 1];
			id[i + 1] = i + 1;
		}
		m = n - 1;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}
		dfs(1, 0);
		for (i = 0; i < n; i++) {
			cout << res[i + 1] << " ";
		}
	}
}