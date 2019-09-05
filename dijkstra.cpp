#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--)
  {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> v[n];
    int a[n + 1][n + 1];
    memset(a, INT_MAX, sizeof(a));
    for (i = 0; i < m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      v[x].push_back(y);
      v[y].push_back(x);
      a[x][y] = w;
      a[y][x] = w;
    }
    int mindis[n + 1];
    for (i = 0; i <= n; i++) {
      mindis[i] = INT_MAX;
    }
    priority_queue<pair<int, int>> Q;
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    Q.push({0, 0});
    mindis[0] = 0;
    while (!Q.empty()) {
      int cur = Q.top().second;
      Q.pop();
      if (vis[cur]) {
        continue;
      }
      vis[cur] = true;
      for (int x : v[cur]) {
        if (mindis[cur] + a[cur][x] < mindis[x]) {
          mindis[x] = mindis[cur] + a[cur][x];
          Q.push({ -mindis[x], x});
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << "0 -->" << i << "= " << mindis[i] << '\n';
    }
  }
}
