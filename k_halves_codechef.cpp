#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 305;
int a[N], n, cnt, memo[N];

int give(int l, int r) {
	int ans = 0;
	for (int i = l; i <= (l + r) / 2; i++) {
		ans += a[i];
	}
	return ans;
}

int solve(int cur) {
	if (cur >= n) return 0;
	if (memo[cur] != -1e18) return memo[cur];
	int ans = -1e18;
	for (int i = cur + 1 ; i < n; i += 2) {
		ans = max(ans, solve(i + 1) + give(cur, i));
	}
	return memo[cur] = ans;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, m, ans = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n; i++) {
			memo[i] = -1e18;
		}
		cout << solve(0) << '\n';
	}
}