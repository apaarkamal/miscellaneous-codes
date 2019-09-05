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

const int N = 100005;

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0, a, b;
        cin >> n >> m >> a >> b;
        int grid[n + 1][m + 1], sm[n + 1][m + 1], g[n * m + 10];
        int x, y, z;
        cin >> g[0] >> x >> y >> z;
        for (i = 1; i < n * m + 10; i++) {
            g[i] = g[i - 1] * x + y; g[i] %= z;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                grid[i - 1][j - 1] = g[(i - 1) * m + j - 1];
            }
        }
        for (i = 0; i < n; i++) {
            deque<P> Q;
            for (j = 0; j < b; j++) {
                while (!Q.empty() && Q.back().F >= grid[i][j]) {
                    Q.pop_back();
                }
                Q.push_back({grid[i][j], j});
            }
            sm[i][0] = Q.front().F;
            for (j = b; j < m; j++) {
                if (Q.front().S == j - b) {
                    Q.pop_front();
                }
                while (!Q.empty() && Q.back().F >= grid[i][j]) {
                    Q.pop_back();
                }
                Q.push_back({grid[i][j], j});
                sm[i][j - b + 1] = Q.front().F;
            }
        }
        // for(i=0;i<n;i++){
        //     for(j=0;j<m;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        // for(i=0;i<n;i++){
        //     for(j=0;j<=m-b;j++){
        //         cout<<sm[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        for (j = 0; j < m - b + 1; j++) {
            deque<P> Q;
            for (i = 0; i < a; i++) {
                while (!Q.empty() && Q.back().F >= sm[i][j]) {
                    Q.pop_back();
                }
                Q.push_back({sm[i][j], i});
            }
            ans += Q.front().F;
            for (i = a; i < n; i++) {
                if (Q.front().S == i - a) {
                    Q.pop_front();
                }
                while (!Q.empty() && Q.back().F >= sm[i][j]) {
                    Q.pop_back();
                }
                Q.push_back({sm[i][j], i});
                ans += Q.front().F;
            }
        }
        cout << ans;
    }
}