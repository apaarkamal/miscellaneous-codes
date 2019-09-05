// https://codeforces.com/contest/739/problem/B

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

const int N = 200005, M = 18;

V<P> v[N];
int a[N], Par[N][M], Dis[N][M], dp[N];

void dfs(int cur) {
    int i, j;
    for (i = 1; i < M; i++) {
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
        Dis[cur][i] = Dis[cur][i - 1] + Dis[Par[cur][i - 1]][i - 1];
    }
    int u = cur, x = a[cur];
    for (i = M - 1; i >= 0; i--) {
        if (Dis[u][i] <= x) {
            x -= Dis[u][i]; u = Par[u][i];
        }
    }
    dp[Par[u][0]]--;
    dp[cur]++;
    for (auto x : v[cur]) {
        dfs(x.F);
    }
}

void dfs1(int cur) {
    for (auto x : v[cur]) {
        dfs1(x.F);
        dp[cur] += dp[x.F];
    }
}

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
        for (i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        for (i = 0; i < n; i++) {
            int p, w;
            cin >> p >> w;
            v[p].pb({i + 2, w});
            Par[i + 2][0] = p;
            Dis[i + 2][0] = w;
        }
        dfs(1);
        dfs1(1);
        for (i = 0; i < n; i++) {
            cout << dp[i + 1] - 1 << " ";
        }
    }
}