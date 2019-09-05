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

const ll N = 100001;

void go(ll n, ll open, ll close, string s) {
    if (open + close > n || open > n / 2 || close > n / 2) {
        return;
    }
    if (open == close && open + close == n) {
        cout << s << '\n'; return;
    }
    if (open > close) {
        go(n, open, close + 1, s + ")");
    }
    go(n, open + 1, close, s + "(");
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
        ll i, j, k, n, m, ans = 0, cnt = 0;
        cin >> n;
        n *= 2;
        go(n, 1ll, 0ll, "(");
    }
}