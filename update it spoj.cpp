#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

void the_martian() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}

const int N = 10005;

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
            x -= (x & -x);
        }
        return ret;
    }
} bit;


int32_t main()
{
    the_martian();
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < n + 5; i++) {
            bit.a[i] = 0;
        }
        while (m--) {
            int l, r, val;
            cin >> l >> r >> val;
            bit.add(l, val);
            bit.add(r + 1, -val);
        }
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            cout << bit.sum(x) << '\n';
        }
    }
}