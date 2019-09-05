// https://codeforces.com/contest/1167/problem/F
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 500005;

const int mod = 1000000007;
int fact[N], invfact[N];
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x;}
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x;}
inline int mul(int x, int y) { return (((int) x) * y) % mod;}
inline int powr(int a, int b) {
    int x = 1 % mod;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a) { return powr(a, mod - 2);}
void pre() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
    assert(invfact[1] == 1);
}

inline int C(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

class BIT
{
public:
    int a[N];
    // bit.add(i,a[i]);
    // sum=bit.sum(i);
    void add(int x, int val)
    {
        x++;
        while (x < N)
        {
            a[x] += val;
            a[x] %= mod;
            x += (x & -x);
        }
    }
    int sum(int x)
    {
        int ret = 0;
        x++;
        while (x)
        {
            ret += a[x];
            ret %= mod;
            x -= (x & -x);
        }
        return ret;
    }
    int sum(int l, int r) {
        int ret = sum(r) - sum(l - 1) + mod;
        ret %= mod;
        return ret;
    }
} bit1, bit2;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int a[n + 1];
        V<P> v;
        for (i = 0; i < n; i++) {
            cin >> a[i + 1];
            v.pb({a[i + 1], i + 1});
        }
        sort(v.begin(), v.end());
        for (i = 0; i < n; i++) {
            int ind = v[i].S;
            bit1.add(ind, ind);
            bit2.add(ind, n - ind + 1);
            ans += (n - ind + 1) * bit1.sum(1, ind - 1) * a[ind]; ans %= mod;
            db(ans);
            ans += ind * bit2.sum(ind + 1, n) * a[ind]; ans %= mod;
            db(ans);
            ans += ind * (n - ind + 1) * a[ind]; ans %= mod;
            db(ans);
        }
        cout << ans;
    }
}