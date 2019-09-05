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

const ll mod = 1000000007;
ll fact[N], invfact[N];
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll sub(ll x, ll y) { x -= y; if (x < 0) x += mod; return x;}
inline ll mul(ll x, ll y) { return (((ll) x) * y) % mod;}
inline ll powr(ll a, ll b) {
    ll x = 1 % mod;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return powr(a, mod - 2);}
void pre() {
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[N - 1] = inv(fact[N - 1]);
    for (ll i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
    assert(invfact[1] == 1);
}

inline ll C(ll n, ll k) {
    if (n < k || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

ll givecnt(ll cnt) {
    ll ans = 0;
    for (ll k = 1; k <= cnt; k++) {
        ans += (cnt - k + 1) * k; ans %= mod;
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
        ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0, prev = 0;
        cin >> n;
        ll a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<ll, ll> mp;
        j = 0; ans = 0;
        for (i = 0; i < n; i++) {
            while (j < n && mp[a[j]] == 0) {
                mp[a[j]]++; j++;
            }
            ans += (j - i) * (j - i + 1) * inv(2);
            ans %= mod;
            mp[a[i]]--;
        }
        cout << ans;
    }
}