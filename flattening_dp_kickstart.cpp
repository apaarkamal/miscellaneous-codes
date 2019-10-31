// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666c
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

const int N = 1000005, M = 101;

int dp[M][M], n, res, a[M], memo[M][M];

int give(int l, int r) {
	if (memo[l][r] != -1) return memo[l][r];
	map<int, int> mp;
	for (int i = l; i <= r; i++) {
		mp[a[i]]++;
	}
	int cnt = 0;
	for (auto x : mp) {
		cnt = max(cnt, x.S);
	}
	return memo[l][r] = (r - l + 1) - cnt;
}

void go(int cur, int k, int cnt) {
	if (k < 0) return;
	if (k == 0 && cur == n) {
		res = min(res, cnt);
	}
	for (int i = cur; i < n; i++) {
		go(i + 1, k - 1, cnt + give(cur, i));
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, z = 1; cin >> t; while (t--)
	{
		int i, j, k, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> k;
		for (i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1) {
				if (a[i] != a[i - 1]) {
					cnt++;
				}
			}
		}
		if (cnt <= k) {
			cout << "Case #" << z++ << ": " << 0 << '\n';
			continue;
		}
		k++;
		for (i = 1; i <= n; i++) {
			for (j = 0; j <= k; j++) {
				dp[i][j] = 200;
			}
			map<int, int> mp;
			int mx = 0;
			for (j = i; j > 0; j--) {
				mp[a[j]]++;
				mx = max(mx, mp[a[j]]);
				for (int kk = 1; kk <= k; kk++) {
					dp[i][kk] = min(dp[i][kk], dp[j - 1][kk - 1] + (i - j + 1) - mx);
				}
			}
		}
		cout << "Case #" << z++ << ": " << dp[n][k] << '\n';
	}
}
// 4
// 8 2
// 300 100 300 300 200 100 800 500
// 5 3
// 100 100 100 100 3
// 7 3
// 10 20 40 10 10 30 30
// 10 2
// 30 30 60 60 90 90 60 60 30 30