// https://codeforces.com/contest/401/problem/D
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M = 20, K = 100;
int dp[1 << M][K], freq[10], fact[20];

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		string s;
		cin >> s >> m;
		n = s.size();
		for (i = 0; i < n; i++) {
			freq[s[i] - '0']++;
		}
		fact[0] = 1;
		for (i = 1; i < 20; i++) {
			fact[i] = fact[i - 1] * i;
		}
		dp[0][0] = 1;
		for (int mask = 1; mask < (1 << 18); mask++) {
			for (k = 0; k < m; k++) {
				for (i = 0; i < n; i++) {
					if ((mask >> i) & 1) {
						if (s[i] - '0' == 0 && (1 << i) == mask) continue;
						dp[mask][(k * 10 + s[i] - '0') % m] += dp[mask ^ (1ll << i)][k];
					}
				}
			}
		}
		for (i = 0; i < 10; i++) {
			dp[(1 << n) - 1][0] /= fact[freq[i]];
		}
		cout << dp[(1 << n) - 1][0];
	}
}