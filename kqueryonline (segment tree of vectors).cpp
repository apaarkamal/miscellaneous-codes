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

const ll N = 300005;
vector<ll> st[N];
ll a[N];

void build(ll l, ll r, ll node) {
    if (l == r) {
        st[node].pb(a[l]);
        return;
    }
    ll mid = (l + r) / 2;
    build(l, mid, node * 2 + 1);
    build(mid + 1, r, node * 2 + 2);
    merge(st[node * 2 + 1].begin(), st[node * 2 + 1].end(), st[node * 2 + 2].begin(), st[node * 2 + 2].end(), back_inserter(st[node]));
}

ll getans(ll si, ll se, ll l, ll r, ll node, ll k) {
    // cout<<si<<" "<<se<<'\n';
    if (se < l || si > r) {
        return 0;
    }
    if (si >= l && se <= r) {
        return st[node].size() - (upper_bound(st[node].begin(), st[node].end(), k) - st[node].begin());
    }
    ll mid = (si + se) / 2;
    ll q1 = getans(si, mid, l, r, node * 2 + 1, k);
    ll q2 = getans(mid + 1, se, l, r, node * 2 + 2, k);
    return q1 + q2;
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
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(0, n - 1, 0);
        cin >> m;
        while (m--) {
            ll l, r;
            cin >> l >> r >> k;
            l ^= ans; r ^= ans; k ^= ans;
            l--; r--;
            ans = getans(0, n - 1, l, r, 0, k);
            cout << ans << '\n';
        }
    }
}