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

const int N = 100005;

vector<P> temp;
vector<pair<int, P>> col[N], row[N], vv;
int rowmax[N], colmax[N], n, m, dp[N], vis[N], cnt;

int convert(int x, int y) {
    return x * m + y;
}

void dfs(int x, int y, int val) {
    cnt = max(rowmax[x], colmax[y]);
    temp.pb({x, y});
    vis[convert(x, y)] = 1;
    pair<int, P> p = {val, { -1, -1}};
    int it = lower_bound(row[x].begin(), row[x].end(), p) - row[x].begin();
    for (int i = it; i < row[x].size(); i++) {
        if (row[x][i].F > val) break;
        if (vis[convert(row[x][i].S.F, row[x][i].S.S)] == 0 && val == row[x][i].F) {
            dfs(row[x][i].S.F, row[x][i].S.S, val);
        }
    }
    it = lower_bound(col[y].begin(), col[y].end(), p) - col[y].begin();
    for (int i = it; i < col[y].size(); i++) {
        if (col[y][i].F > val) break;
        if (vis[convert(col[y][i].S.F, col[y][i].S.S)] == 0 && val == col[y][i].F) {
            dfs(col[y][i].S.F, col[y][i].S.S, val);
        }
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i, j, k, ans = 0, sum = 0;
        cin >> n >> m;
        int a[n][m];
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
                row[i].pb({a[i][j], {i, j}});
                col[j].pb({a[i][j], {i, j}});
                vv.pb({a[i][j], {i, j}});
            }
        }
        for (i = 0; i < n; i++) {
            sort(row[i].begin(), row[i].end());
        }
        for (i = 0; i < m; i++) {
            sort(col[i].begin(), col[i].end());
        }
        sort(vv.begin(), vv.end());
        for (auto xx : vv) {
            if (vis[convert(xx.S.F, xx.S.S)]) continue;
            cnt = 0;
            temp.clear();
            dfs(xx.S.F, xx.S.S, xx.F);
            for (auto x : temp) {
                dp[convert(x.F, x.S)] = cnt + 1;
                rowmax[x.F] = cnt + 1;
                colmax[x.S] = cnt + 1;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << dp[convert(i, j)] << " ";
            }
            cout << '\n';
        }
    }
}