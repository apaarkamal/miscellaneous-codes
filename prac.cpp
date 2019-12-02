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

const int N = 100005;

vector<string> all;
map<string, int> mp;
map<int, string> mpr;

vector<string> give(string s) {
	vector<string> res;
	int i, j, k, l, n = s.size();
	for (i = 0; i < n; i++) {
		res.pb(s.substr(i, 1));
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j  < n; j++) {
			res.pb(s.substr(i, 1) + s.substr(j, 1));
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j  < n; j++) {
			for (k = j + 1 ; k < n; k++) {
				res.pb(s.substr(i, 1) + s.substr(j, 1) + s.substr(k, 1));
			}
		}
	}
	for (i = 0; i  < n; i++) {
		for (j = i + 1; j  < n; j++) {
			for (k = j + 1 ; k < n; k++) {
				for (l = k + 1 ; l < n; l++) {
					res.pb(s.substr(i, 1) + s.substr(j, 1) + s.substr(k, 1) + s.substr(l, 1));
				}
			}
		}
	}
	sort(res.begin(), res.end());
	res.resize(unique(res.begin(), res.end()) - res.begin());
	return res;
}

struct BipartiteMatcher {
	vector<vector<int>> G;
	vector<int> L, R, Viz;
	void init(int n, int m)//left n, right m nodes
	{
		G.clear(), L.clear(), R.clear(), Viz.clear();
		G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
	}
	void AddEdge(int a, int b) { G[a].push_back(b); }
	bool Match(int node) {
		if (Viz[node]) return 0;
		Viz[node] = 1;
		for (auto vec : G[node]) {
			if (R[vec] == -1 || Match(R[vec])) {
				L[node] = vec; //left connected to which on right
				R[vec] = node; //right connected to which on left
				return 1;
			}
		}
		return 0;
	}
	int Solve() {
		bool ok = 1;
		while (ok) {
			ok = 0;
			fill(Viz.begin(), Viz.end(), 0);
			for (int i = 0; i < L.size(); i++)
				if (L[i] == -1)
					ok |= Match(i);
		}
		int ret = 0;
		for (int i = 0; i < L.size(); i++)
			ret += (L[i] != -1);
		return ret;
	}
} G;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0;
		cin >> n;
		string s[n];
		G.init(n, 475254);
		for (i = 0; i < n; i++) {
			cin >> s[i];
			vector<string> res = give(s[i]);
			for (j = 0; j < res.size(); j++) {
				if (mp.count(res[j])) {
					G.AddEdge(i, mp[res[j]]);
				}
				else {
					mpr[cnt] = res[j];
					mp[res[j]] = cnt++;
					G.AddEdge(i, mp[res[j]]);
				}
			}
		}
		if (G.Solve() == n) {
			for (i = 0; i < n; i++) {
				cout << mpr[G.L[i]] << '\n';
			}
		}
		else {
			cout << -1;
		}
	}
}