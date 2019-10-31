#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) _f(#VA_ARGS, __VA_ARGS_)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 10000005, M = 1e18;

int ptr = 2;

struct node {
	int lf = 0, rt = 0, val = 0;
};

node tree[N];

int query(int st, int en, int l, int r, int node) {
	if (node == 0 || en < l || st > r) {
		return 0;
	}
	if (l <= st && en <= r) {
		return tree[node].val;
	}
	int mid = (st + en) / 2;
	int q1 = query(st, mid, l, r, tree[node].lf);
	int q2 = query(mid + 1, en, l, r, tree[node].rt);
	return q1 + q2;
}

int update(int st, int en, int idx, int val, int node) {
	if (node == 0) {
		node = ptr++;
	}
	if (st == en) {
		tree[node].val = val;
		return node;
	}
	else {
		int mid = (st + en) / 2;
		if (idx <= mid) {
			tree[node].lf = update(st, mid, idx, val, tree[node].lf);
		}
		else {
			tree[node].rt = update(mid + 1, en, idx, val, tree[node].rt);
		}
		tree[node].val = tree[tree[node].lf].val + tree[tree[node].rt].val;
	}
	return node;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		int m1, m2;
		cin >> m >> m1 >> m2;
		int root = 1;
		while (m--) {
			int type;
			cin >> type;
			if (type == 1) {
				int a, b;
				cin >> a >> b;
				a = (a + ans) % m1 + 1;
				b = (b + ans) % m2 + 1;
				root = update(0, M, a, b, root);
			}
			else {
				int a;
				cin >> a;
				a = (a + ans) % m1 + 1;
				ans = query(0, M, 0, a, root);
				cout << ans << '\n';
			}
		}
	}
}