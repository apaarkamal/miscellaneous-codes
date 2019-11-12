/* Apaar $axena */

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;
int pre_xor[N];

int32_t main()
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
		int best[m];
		memset(best, 0, sizeof(best));
		for (i = 0; i < m; i++) {
			cin >> q[i].F >> q[i].S;
			q[i].F--; q[i].S--;
		}
		for (i = 0; i < n; i++) {
			int mx = 0;
			for (j = i + 1; j < n; j++) {

			}
		}
	}
}