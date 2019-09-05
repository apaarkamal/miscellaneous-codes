// https://codeforces.com/contest/1092/problem/F
// https://codeforces.com/contest/1187/problem/E
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


void the_martian() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}

const int N = 200005;

vector<int> gr[N];
int ans = 0, sub[N], f = 0, n;

void dfs(int cur, int par) {
    sub[cur] = 1;
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
            sub[cur] += sub[x];
        }
    }
    ans += sub[cur];
}

void dfs1(int cur, int par, int res) {
    f = max(f, res);
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs1(x, cur, res + n - 2 * sub[x]);
        }
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i, j, k, m, cnt = 0, sum = 0, prev = N + 10;
        cin >> n;
        for (i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        dfs(1, 0);
        dfs1(1, 0, ans);
        cout << f;
    }
}