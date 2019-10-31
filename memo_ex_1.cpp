//https://www.spoj.com/problems/ASSIGN/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;
int n, a[20][20];
int dp[20][1 << 20];

int solve(int row, int mask) {
	if (row == n) return 1;
	int &ans = dp[row][mask];
	if (ans != -1) return ans;
	ans = 0;
	for (int j = 0; j < n; j++) {
		if (a[row][j] && !((1 << j)&mask)) {
			ans += solve(row + 1, mask ^ (1 << j));
		}
	}
	return ans;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0) << '\n';
	}
}