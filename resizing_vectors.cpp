#include<bits/stdc++.h>

using namespace std;

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

int n, m;
vector<string> s, t;
vector<vector<int>> dp, dp1;
vector<P> mark;

bool check(int x) {
	mark.clear();
	int i, j;
	for (i = x; i + x < n; i++) {
		for (j = x; j + x < m; j++) {
			int x1 = i - x, y1 = j - x, x2 = i + x, y2 = j + x;
			int cnt = dp[x2][y2];
			if (x1 > 0) cnt -= dp[x1 - 1][y2];
			if (y1 > 0) cnt -= dp[x2][y1 - 1];
			if (x1 > 0 && y1 > 0) cnt += dp[x1 - 1][y1 - 1];
			int tot_cnt = (x2 - x1 + 1) * (y2 - y1 + 1);
			if (cnt == tot_cnt) {
				mark.pb({i, j});
			}
		}
	}
	dp1.clear();
	dp1.resize(n);
	for (i = 0; i < n; i++) {
		dp1[i].resize(m, 0);
	}
	for (auto xx : mark) {
		i = xx.F, j = xx.S;
		int x1 = i - x, y1 = j - x, x2 = i + x, y2 = j + x;
		dp1[x1][y1] += 1;
		if (x2 + 1 < n && y2 + 1 < m) dp1[x2 + 1][y2 + 1] += 1;
		if (y2 + 1 < m) dp1[x1][y2 + 1] -= 1;
		if (x2 + 1 < n) dp1[x2 + 1][y1] -= 1;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++) {
			dp1[i][j] += dp1[i][j - 1];
		}
	}
	for (j = 0; j < m; j++) {
		for (i = 1; i < n; i++) {
			dp1[i][j] += dp1[i - 1][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (s[i][j] == 'X' && dp1[i][j] <= 0) return false;
		}
	}
	return true;
}

int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	{
		int i, j, k, ans = 0, cnt = 0;
		cin >> n >> m;
		s.resize(n);
		t.resize(n);
		//////////////
		dp = vector<vector<int>>(n, vector<int>(m, 0));
		/////////////
		for (i = 0; i < n; i++) {
			s[i].resize(m);
			t[i].resize(m);
		}
		for (i = 0; i < n; i++) {
			cin >> s[i];
			for (j = 0; j < m; j++) {
				dp[i][j] = s[i][j] == 'X';
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 1; j < m; j++) {
				dp[i][j] += dp[i][j - 1];
			}
		}
		for (j = 0; j < m; j++) {
			for (i = 1; i < n; i++) {
				dp[i][j] += dp[i - 1][j];
			}
		}
		int lf = 0, rt = max(n, m) / 2;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			if (check(mid)) {
				ans = mid;
				lf = mid + 1;
			}
			else {
				rt = mid - 1;
			}
		}
		cout << ans << '\n';
		check(ans);
		t.clear();
		t.resize(n);
		for (i = 0; i < n; i++) {
			t[i].resize(m, '.');
		}
		for (auto x : mark) {
			t[x.F][x.S] = 'X';
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cout << t[i][j];
			}
			cout << '\n';
		}
	}
}