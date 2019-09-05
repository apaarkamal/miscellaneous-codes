#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 200005;
ll p[N];
ll get(ll x) {
  return (x == p[x] ? x : (p[x] = get(p[x])));
}

void unite(ll x, ll y) {
  x = get(x);
  y = get(y);
  if (x != y) {
    p[x] = y;
  }
}
//initially everyone is parent of itself
int main()
{
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // ll t;
  // cin>>t;
  // while(t--)
  {
    ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for (i = 0; i < N; i++) {
      p[i] = i;
    }
    vector<pair<ll, pair<ll, ll>>> v;
    for (i = 0; i < m; i++) {
      ll x, y, w;
      cin >> x >> y >> w;
      v.push_back({w, {x, y}});
    }
    sort(v.begin(), v.end());
    for (i = 0; i < v.size(); i++) {
      ll x = get(v[i].second.first);
      ll y = get(v[i].second.second);
      // cout<<x<<" "<<y<<'\n';
      if (x != y) {
        cout << v[i].second.first << " " << v[i].second.second << " " << v[i].first << '\n';
        unite(v[i].second.second, v[i].second.first);
      }
    }
  }
}
