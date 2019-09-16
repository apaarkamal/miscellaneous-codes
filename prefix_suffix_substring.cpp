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

void buildlpsarray(string pat, int *lps) {
	int m = pat.size(), i = 0, j = 0;
	lps[0] = 0;
	i = 1;
	while (i < m) {
		if (pat[i] == pat[j]) {
			lps[i] = j + 1;
			j++; i++;
		}
		else {
			if (j == 0) {
				lps[i] = 0;
				i++;
			}
			else {
				j = lps[j - 1];
			}
		}
	}
	// lps[m-1] indicates length of
	// longest suffix which is also a prefix
	// of course whole string will be longest
	// suffix which is prefix
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		string s;
		cin >> s >> k;
		n = s.size();
		int lps[n];
		buildlpsarray(s, lps);
		int dp[n + 1] = {};
		for (i = 1; i < k; i++) {
			dp[lps[i]]++;
		}
		j = n;
		while (j > 0) {
			j = lps[j - 1];
			if (dp[j] && j > 0) {
				break;
			}
		}
		if (j) cout << s.substr(0, j) << '\n';
		else cout << "Puchi is a cheat!\n";
	}
}