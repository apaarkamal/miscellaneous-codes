// https://codeforces.com/contest/432/problem/D
// z[i] array tells you the size of substring starting
// from that position which is also prefix
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> z_f(string s)
{
	int len = s.size(), l = 0, r = 0;
	vector<int> z(len, 0);
	for (int i = 1; i < len; i++) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < len && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, sum = 0;
		string s;
		cin >> s;
		n = s.size();
		vector<int> z = z_f(s);
		z[0] = n;
		int cnt[n] = {};
		for (i = 0; i < n; i++) {
			cnt[z[i] - 1]++;
		}
		// for (i = 0; i < n; i++) {
		// 	cout << cnt[i] << " ";
		// }
		for (i = n - 2; i >= 0; i--) {
			cnt[i] += cnt[i + 1];
		}
		vector<P> ansv;
		for (i = 0; i < n; i++) {
			if (z[n - i - 1] == i + 1) {
				ansv.pb({i + 1, cnt[i]});
			}
		}
		cout << ansv.size() << '\n';
		for (auto x : ansv) {
			cout << x.F << " " << x.S << '\n';
		}
	}
}