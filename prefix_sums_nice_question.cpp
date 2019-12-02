/* Apaar $axena */
// https://codeforces.com/contest/628/problem/E
#include<bits/stdc++.h>

using namespace std;

// #define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 3005;

struct fenwick {
	vector<int> fn;
	int n;
	void init() {
		n = 2 * N + 10;
		fn.clear(); fn.resize(n, 0);
	}
	void add(int x, int val) {
		x++;// 1 based indexing
		while (x <= n) {
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x) {
		x++;//1 basaed indexing
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
} bit[2 * N];

int a[N][N], dpl[N][N], dpr[N][N], dpld[N][N];
vector<P> contri[N][N];
string s[N];

int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, cnt = 0;
		long long ans = 0;
		cin >> n >> m;
		for (i = 0; i < n; i++) {
			cin >> s[i];
			for (j = 0; j < m; j++) {
				a[i][j] = s[i][j] == 'z';
				dpl[i][j] = dpr[i][j] = dpld[i][j] = a[i][j];
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 1; j < m; j++) {
				if (a[i][j]) dpl[i][j] += dpl[i][j - 1];
				else dpl[i][j] = 0;
			}
			for (j = m - 2; j >= 0; j--) {
				if (a[i][j]) dpr[i][j] += dpr[i][j + 1];
				else dpr[i][j] = 0;
			}
		}
		for (i = n - 2; i >= 0; i--) {
			for (j = 1; j < m; j++) {
				if (a[i][j]) dpld[i][j] += dpld[i + 1][j - 1];
				else dpld[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (dpr[i][j]) contri[i][j + dpr[i][j] - 1].pb({i, j});
			}
		}
		for (i = 0; i < n + m; i++) {
			bit[i].init();
		}
		for (j = m - 1; j >= 0; j--) {
			for (i = 0; i < n; i++) {
				for (auto x : contri[i][j]) {
					bit[x.F + x.S].add(x.S, 1);
				}
			}
			for (i = n - 1; i >= 0; i--) {
				if (!a[i][j]) continue;
				cnt = min(dpl[i][j], dpld[i][j]);
				ans += 1ll * (bit[i + j].sum(j) - bit[i + j].sum(j - cnt));
			}
		}
		cout << ans;
	}
}