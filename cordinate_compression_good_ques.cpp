// Author : Apaar
// Built  : 22-10-2019 11:42:00
// https://codeforces.com/gym/100733/problem/F
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

struct segmenttree {
	vector<int> st;
	void init(int _n) {
		st.clear();
		st.resize(4 * _n, INT_MIN);
	}

	void update(int l, int r, int indup, int val, int node) {
		if (l == r) {
			st[node] = max(val, st[node]);
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, node * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, node * 2 + 2);
			}
			st[node] = max(st[2 * node + 1], st[2 * node + 2]);
		}
	}

	int query(int si, int se, int l, int r, int node) {
		if (se < l || si > r || l > r) {
			return INT_MIN;
		}
		if (si >= l && se <= r) {
			return st[node];
		}
		int mid = (si + se) / 2;
		int q1 = query(si, mid, l, r, node * 2 + 1);
		int q2 = query(mid + 1, se, l, r, node * 2 + 2);
		return max(q1, q2);
	}
} tree;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n], b[n], c[n], d[n], e[n], f[n];
		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			d[i] = a[i]; e[i] = a[i]; f[i] = a[i];
		}
		sort(d, d + n);
		sort(f, f + n);
		m = unique(d, d + n) - d;
		for (i = 0; i < n; i++) {
			e[i] = lower_bound(d, d + m, e[i]) - d;
		}
		tree.init(n);
		for (i = 0; i < n; i++) {
			int l = max(a[i] - c[i], 0ll), r = e[i];
			int id = lower_bound(f, f + n, l) - f;
			l = f[id];
			l = lower_bound(d, d + m, l) - d;
			cnt = tree.query(0, n - 1, l, r, 0);
			if (cnt == INT_MIN) cnt = 0;
			cnt += b[i];
			tree.update(0, n - 1, r, cnt, 0);
		}
		cout << tree.query(0, n - 1, 0, n - 1, 0);
	}
}