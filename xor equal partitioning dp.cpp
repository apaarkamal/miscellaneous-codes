// https://atcoder.jp/contests/diverta2019/tasks/diverta2019_e
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define PB push_back
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
    x = 0; char c = getchar(); int f = 1;
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 - '0' + c, c = getchar(); x *= f;
}
const int mod = 1e9 + 7, N = 5e5 + 10;
void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int f[2][N], a[N], n;
vector<int> b[1 << 20];
int buc[N];
int dp[N], s1[N], s2[N];
int solve(vector<int> &p) {
    int m = p.size() - 1, ans = 0;
    for (int i = 0; i <= m; ++i) dp[i] = s1[i] = s2[i] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i] = ((buc[p[i]] * (ll)s1[i - 1] - s2[i - 1] + 1) % mod + mod) % mod;
        s1[i] = (s1[i - 1] + dp[i]) % mod;
        s2[i] = (s2[i - 1] + dp[i] * (ll)buc[p[i]] % mod) % mod;
        Add(ans, dp[i]);
    }
    return ans;
}
int main() {
    rd(n);
    for (int i = 1; i <= n; ++i) rd(a[i]), a[i] ^= a[i - 1];
    int ans = 0;
    if (a[n]) {
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[0][i] = f[0][i - 1];
            f[1][i] = f[1][i - 1];
            if (a[i] == a[n]) Add(f[1][i], f[0][i - 1]);
            if (a[i] == 0) Add(f[0][i], f[1][i - 1]);
        }
        ans = f[0][n - 1];
    }
    else {
        for (int i = 1; i <= n; ++i) buc[i] = buc[i - 1] + (a[i] == 0);
        for (int i = 0; i < (1 << 20); ++i) b[i].PB(0);
        for (int i = 1; i <= n; ++i)
            if (a[i]) b[a[i]].PB(i);
        for (int i = 0; i < (1 << 20); ++i)
            if (b[i].size() > 1) Add(ans, solve(b[i]));
        int t = 1;
        for (int i = 1; i < buc[n]; ++i) t = t * 2ll % mod;
        Add(ans, t);
    }
    printf("%d", ans);
    return 0;
}