#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 200005, M = 11;

map<int, int> dp[M];
int pow10[M];

int give_length(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x /= 10;
	}
	return cnt;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, n, k, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> k;
		pow10[0] = 1;
		for (int i = 1; i < M; i++) {
			pow10[i] = pow10[i - 1] * 10;
			pow10[i] %= k;
		}
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
			int dig = give_length(a[i]);
			dp[dig][a[i] % k]++;
		}
		for (j = 1; j < M; j++) {
			for (i = 0; i < n; i++) {
				int val = ((a[i] % k) * pow10[j]) % k;
				int need = (k - val) % k;
				ans += dp[j][need];
			}
		}
		for (i = 0; i < n; i++) {
			int num = ((a[i] % k) * (pow10[give_length(a[i])] + 1)) % k;
			if (num % k == 0) ans--;
		}
		cout << ans;
	}
}