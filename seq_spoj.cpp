#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

const int N = 100005;

const int mod = 1e9;

const int M = 11;
int sz;
struct Mat
{
    int m[M][M];

    Mat()
    {
        memset(m, 0, sizeof m);
    }

    void eye()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
    }

    Mat operator* (const Mat &a) const
    {
        Mat r;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
        return r;
    }
};
int solve(int b[], int c[], int e, int n)
{
    Mat r, a;
    r.eye();
    for (int i = 0; i < n; i++) {
        a.m[0][i] = c[i];
    }
    for (int i = 1; i < n; i++) {
        a.m[i][i - 1] = 1;
    }
    while (e)
    {
        if (e & 1)
            r = r * a;
        a = a * a;
        e >>= 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += r.m[0][i] * b[n - i - 1];
        ans %= mod;
    }
    return ans;
}

int32_t main()
{
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        sz = n;
        int b[n], c[n];
        for (i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (i = 0; i < n; i++) {
            cin >> c[i];
        }
        cin >> k;
        k--;
        if (k < n) {
            cout << b[k] << '\n';
        }
        else {
            cout << solve(b, c, k - n + 1, n) << '\n';
        }
    }
}