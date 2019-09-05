#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const ll N = 100005;

ll a[N];

bool check(ll mid, ll n, ll m) {
  ll cnt = 0, i;
  for (i = 0; i < n; i++) {
    ll j = 0;
    while ((j * (j + 1))*a[i] <= mid * 2) {
      j++;
    }
    j--;
    cnt += j;
  }
  return cnt >= m;
}

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
    cin >> m;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    ll lf = 0, rt = 1e8;
    while (lf < rt) {
      ll mid = (lf + rt) / 2;
      if (check(mid, n, m)) {
        rt = mid;
      }
      else {
        lf = mid + 1;
      }
    }
    cout << lf;
  }
}