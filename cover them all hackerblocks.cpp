#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

const int N = 200005;

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

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.F.S < b.F.S;
}

class BIT
{
public:
    int a[N + 1];
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
    void clear() {
        for (int i = 0; i <= N; i++) {
            a[i] = 0;
        }
    }
} bit, bit1;

int32_t main()
{
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        pair<pair<int, int>, int> a[n];
        int b[n];
        vector<int> v;
        for (i = 0; i < n; i++) {
            cin >> a[i].F.F;
            v.pb(a[i].F.F);
        }
        for (i = 0; i < n; i++) {
            cin >> a[i].F.S;
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for (i = 0; i < n; i++) {
            a[i].S = lower_bound(v.begin(), v.end(), a[i].F.F) - v.begin() + 1;
        }
        sort(a, a + n, comp);
        bit.add(a[0].S, a[0].F.F);
        bit1.add(a[0].S, 1);
        for (i = 1; i < n; i++) {
            int bigsum = sub(bit.sum(N - 3), bit.sum(a[i].S));
            int bigcnt = sub(bit1.sum(N - 3), bit1.sum(a[i].S));
            int smsum = bit.sum(a[i].S - 1);
            int smcnt = bit1.sum(a[i].S - 1);
            cnt = sub(mul(a[i].F.F, smcnt), smsum);
            cnt = add(cnt, sub(bigsum, mul(a[i].F.F, bigcnt)));
            ans = add(ans, mul(cnt, a[i].F.S));
            bit.add(a[i].S, a[i].F.F);
            bit1.add(a[i].S, 1);
        }
        cout << ans % mod << '\n';
        bit.clear();
        bit1.clear();
    }
}