#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int mod = 998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0, lim - 1);
	return uid(rang);
}
int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

pii a[6005];
struct BipartiteMatcher {
	vector<vector<int>> G;
	vector<int> L, R, Viz;
	void init(int n, int m) {
		G.clear(), L.clear(), R.clear(), Viz.clear();
		G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
	}
	void AddEdge(int a, int b) { G[a].push_back(b); }
	bool Match(int node) {
		if (Viz[node]) return 0;
		Viz[node] = 1;
		for (auto vec : G[node]) {
			if (R[vec] == -1 || Match(R[vec])) {
				L[node] = vec;
				R[vec] = node;
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
			fr(i, 0, L.size() - 1)
			if (L[i] == -1)
				ok |= Match(i);
		}
		int ret = 0;
		fr(i, 0, L.size() - 1)
		ret += (L[i] != -1);
		return ret;
	}
} bm;
void solve() {
	int n;
	cin >> n;
	vi co;
	fr(i, 1, n) {
		cin >> a[i].fi >> a[i].se;
		co.pb(a[i].fi ^ a[i].se);
		co.pb(a[i].fi | a[i].se);
		co.pb(a[i].fi & a[i].se);
	}
	sort(all(co));
	co.resize(unique(all(co)) - co.begin());
	map<int, int> lol;
	for (int i = 0; i < sz(co); i++)
		lol[co[i]] = i;
	bm.init(n + 1, sz(co));
	fr(i, 1, n) {
		bm.AddEdge(i, lol[a[i].fi ^ a[i].se]);
		bm.AddEdge(i, lol[a[i].fi | a[i].se]);
		bm.AddEdge(i, lol[a[i].fi & a[i].se]);
	}
	if (bm.Solve() == n) {
		fr(i, 1, n) {
			cout << a[i].fi << " ";
			if ((a[i].fi ^ a[i].se) == co[bm.L[i]]) {
				cout << '^';
			} else if ((a[i].fi | a[i].se) == co[bm.L[i]]) {
				cout << '|';
			} else if ((a[i].fi & a[i].se) == co[bm.L[i]]) {
				cout << '&';
			}
			cout << " " << a[i].se << " = " << co[bm.L[i]] << endl;
		}
	} else {
		cout << "impossible" << endl;
	}


}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout << fixed << setprecision(12);
	int t = 1;
//	cin>>t;
	fr(i, 1, t)	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
