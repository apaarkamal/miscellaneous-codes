#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 500001;

vector<P> gr[N];

bool vis[N];
int mindis[N];
P dijsktra(int src, int n) {
	priority_queue<P, vector<P>, greater<P>> Q;
	for (int i = 0; i < n ; i++) {
		mindis[i] = INT_MAX;
		vis[i] = false;
	}

	Q.push({0, src}); //{dis,node}
	while (!Q.empty()) {
		P tp = Q.top();
		Q.pop();
		int cur = tp.S;
		int dis = tp.F;
		if (vis[cur]) continue;
		vis[cur] = true;
		mindis[cur] = dis;

		for (auto x : gr[cur]) {
			Q.push({mindis[cur] + x.S, x.F});
		}
	}
	int mx = -1, num = 0;
	for (int i = 0; i < n; i++) {
		if (mindis[i] == INT_MAX) continue;
		mx = max(mx, mindis[i]);
	}
	for (int i = 0; i < n; i++) {
		if (mindis[i] == mx) num++;
	}
	return {mx, num};
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		int q;
		cin >> n >> m >> q;
		for (i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			gr[a].pb({b, c});
			gr[b].pb({a, c});
		}
		while (q--) {
			int arr;
			cin >> arr;
			P pans = dijsktra(arr, n);
			cout << pans.F << " " << pans.S << '\n';
		}
	}
}