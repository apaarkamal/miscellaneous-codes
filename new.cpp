#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

map<int, int> mp;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = (a[i] < 0 ? -1 : 1);
			if (i) a[i] *= a[i - 1];
		}
		int pos = 0, neg = 0;
		mp[1] = 1;
		for (i = 0; i < n; i++) {
			pos += mp[a[i]];
			neg += mp[-a[i]];
			mp[a[i]]++;
		}
		cout << neg << " " << pos;
	}
}