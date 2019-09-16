#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_bac
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 200005, M = 10;

int a[N];

struct node {
	int best;
	int mn[M];
	node() {
		best = INT_MAX;
		for (int i = 0; i < M; i++) mn[i] = INT_MAX;
	}
};

struct segmenttree_noded {
	vector<node> st;
	void init(int _n) {
		st.clear();
		st.resize(4 * _n);
	}

	node merge(node &a, node &b) {
		node c;
		c.best = min(a.best, b.best);
		for (int i = 0; i < M; i++) {
			c.mn[i] = min(a.mn[i] , b.mn[i]);
			if (a.mn[i] < INT_MAX && b.mn[i] < INT_MAX) {
				c.best = min(c.best, a.mn[i] + b.mn[i]);
			}
		}
		return c;
	}

	void update_node(node &a, int val) {
		int x = val;
		for (int i = 0; i < M; i++) {
			if (val % 10) a.mn[i] = x;
			else a.mn[i] = INT_MAX;
			val /= 10;
		}
	}

	void build(int l, int r, int idx) {
		if (l == r) {
			update_node(st[idx], a[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, idx * 2 + 1);
		build(mid + 1, r, idx * 2 + 2);
		st[idx] = merge(st[2 * idx + 1], st[2 * idx + 2]);
	}

	void update(int l, int r, int indup, int val, int idx) {
		if (l == r) {
			a[l] = val;
			update_node(st[idx], a[l]);
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, idx * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, idx * 2 + 2);
			}
			st[idx] = merge(st[2 * idx + 1], st[2 * idx + 2]);
		}
	}

	node query(int si, int se, int l, int r, int idx) {
		if (se < l || si > r || l > r) {
			node temp;
			return temp;
		}
		if (si >= l && se <= r) {
			return st[idx];
		}
		int mid = (si + se) / 2;
		node q1 = query(si, mid, l, r, idx * 2 + 1);
		node q2 = query(mid + 1, se, l, r, idx * 2 + 2);
		return merge(q1, q2);
	}
} tree;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		tree.init(n);
		tree.build(0, n - 1, 0);
		while (m--) {
			int type;
			cin >> type;
			if (type == 1) {
				int x, val;
				cin >> x >> val;
				tree.update(0, n - 1, x - 1, val, 0);
			}
			else {
				int l, r;
				cin >> l >> r;
				l--; r--;
				node best = tree.query(0, n - 1, l, r, 0) ;
				cout << (best.best == INT_MAX ? -1 : best.best) << '\n';
			}
		}
	}
}