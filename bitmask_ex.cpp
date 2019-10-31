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

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		n = 10;
		int dp[1 << n];
		dp[0] = 1;
		for (i = 1; i < (1 << n); i++) {
			dp[i] = 0;
			for (j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					dp[i] += dp[i ^ (1 << j)];
				}
			}
		}
		for (i = 0; i < (1 << n); i++) {
			db(i, dp[i]);
		}
	}
}