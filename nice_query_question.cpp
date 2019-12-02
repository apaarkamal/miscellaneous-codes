/* Apaar $axena */
// https://codeforces.com/contest/620/problem/F
#include<bits/stdc++.h>

using namespace std;

// #define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;
int pre_xor[N];

int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		pre_xor[0] = 0;
		for (i = 1; i < N; i++) {
			pre_xor[i] = pre_xor[i - 1] ^ i;
		}
		cin >> n >> m;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		P q[m];
		int best[m], till[n];
		memset(best, 0, sizeof(best));
		memset(till, 0, sizeof(till));
		for (i = 0; i < m; i++) {
			cin >> q[i].F >> q[i].S;
			q[i].F--; q[i].S--;
		}
		for (i = 0; i < n; i++) {
			int mx = 0;
			for (j = i; j < n; j++) {
				mx = max(mx, pre_xor[a[i]] ^ pre_xor[a[j]] ^ (a[i] < a[j] ? a[i] : a[j]));
				till[j] = mx;
			}
			for (j = 0; j < m; j++) {
				if (q[j].F <= i && i <= q[j].S) {
					best[j] = max(best[j], till[q[j].S]);
				}
			}
		}
		for (i = 0; i < m; i++) {
			cout << best[i] << '\n';
		}
	}
}