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

const ll N = 2005;
ll a[N], b[N];

bool check(ll mid, ll n, ll m, ll k) {
    ll i, j = 0;
    for (i = 0; i < m; i++) {
        if (abs(b[i] - a[j]) + abs(k - b[i]) <= mid) {
            j++;
        }
        if (j == n) {
            return 1;
        }
    }
    return 0;
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
        cin >> n >> m >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + m);
        ll lo = 0, hi = 2e9 + 10;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (check(mid, n, m, k))
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo;
    }
}