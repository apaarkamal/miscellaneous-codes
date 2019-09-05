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

const ll N = 200005;

ll Bit[N];
ll qans[N];

struct query {
    ll id = 0, l = 0, r = 0, val = 0;
} Q[N];

bool comp(query A, query B) {
    if (A.val == B.val) {
        return A.l > B.l;
    }
    return A.val > B.val;
}

void update(ll idx) {
    idx++;
    while (idx < N) {
        Bit[idx]++;
        idx += idx & (-idx);
    }
}

ll query(ll idx) {
    ll ans = 0; idx++;
    while (idx > 0) {
        ans += Bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
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
        ll a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
            Q[i].val = a[i];
            Q[i].l = -1;
            Q[i].r = i;
        }
        cin >> m; cnt = m;
        while (i < n + m) {
            ll l, r;
            cin >> l >> r >> k;
            l--; r--;
            Q[i].l = l;
            Q[i].r = r;
            Q[i].val = k;
            Q[i].id = i - n;
            i++;
        }
        m = i;
        sort(Q, Q + m, comp);
        for (i = 0; i < m; i++) {
            if (Q[i].l == -1) {
                update(Q[i].r);
            }
            else {
                qans[Q[i].id] = query(Q[i].r) - query(Q[i].l - 1);
            }
        }
        for (i = 0; i < cnt; i++) {
            cout << qans[i] << '\n';
        }
    }
}





//////////////////////////////////////////////////////////////
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

ll Bit[N];
ll qans[N];

struct query {
    ll id = 0, l = 0, r = 0, val = 0;
} Q[N];

bool comp(query A, query B) {
    return A.val >= B.val;
}

void update(ll idx, ll n) {
    idx++;
    while (idx <= n) {
        Bit[idx]++;
        idx += idx & (-idx);
    }
}

ll query(ll idx) {
    ll ans = 0; idx++;
    while (idx > 0) {
        ans += Bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
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
        ll a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
            Q[i].val = a[i];
            Q[i].l = -1;
            Q[i].r = i;
        }
        cin >> m; cnt = m;
        while (i < n + m) {
            ll l, r;
            cin >> l >> r >> k;
            l--; r--;
            Q[i].l = l;
            Q[i].r = r;
            Q[i].val = k;
            Q[i].id = i - n;
            i++;
        }
        m = i;
        sort(Q, Q + m, comp);
        for (i = 0; i < m; i++) {
            if (Q[i].l == -1) {
                update(Q[i].r, n);
            }
            else {
                qans[Q[i].id] = query(Q[i].r) - query(Q[i].l - 1);
            }
        }
        for (i = 0; i < cnt; i++) {
            cout << qans[i] << '\n';
        }
    }
}