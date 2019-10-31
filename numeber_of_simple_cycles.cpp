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

int dp[19][1 << 19];
int gr[19][19];
int st;

int dfs(int cur, int mask) {
	if (dp[cur][mask] != -1) return dp[cur][mask];
	int &ans = dp[cur][mask];
	ans = 0;
	if (__builtin_popcount(mask) > 2 && gr[cur][st]) ans = 1;
	for (int i = st; i < 19; i++) {
		if (!((1 << i)&mask) && (gr[cur][i])) {
			ans += dfs(i, mask | (1 << i));
		}
	}
	return ans;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			gr[x][y] = 1;
			gr[y][x] = 1;
		}
		memset(dp, -1, sizeof(dp));
		for (i = 0; i < n; i++) {
			st = i;
			ans += dfs(i, (1 << i));
		}
		cout << ans / 2;
	}
}