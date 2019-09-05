vector<pair<int, int>> gr[N], brdgs;
int tin[N], tout[N], low[N], vis[N], tme = 1, chld[N];
vector<int> art_p;

void dfs(int cur, int par) {
    vis[cur] = low[cur] = tme++;
    for (auto &x : gr[cur]) {
        if (!vis[x.F]) {
            dfs(x.F, cur);
            chld[cur]++;
            low[cur] = min(low[cur], low[x.F]);
            if (par && low[x.F] >= vis[cur]) {
                art_p.pb(cur);
            }
            if (low[x.F] > vis[cur]) {
                brdgs.pb({cur, x.F});
                brdgs.pb({x.F, cur});
                //remember if cur->x.F is bridge edge then
                // x.F->cur will also be bridge edges
                x.S = 1; // bridge edge
            }
        }
        else if (x.F != par) {
            low[cur] = min(low[cur], vis[x.F]);
        }
    }
    if (par == 0 && chld[cur] > 1) art_p.pb(cur); // for root
}

//////////////////////////////////////////////////////////////

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> gr[N], art_p;
int tin[N], tout[N], low[N], vis[N], tme, chld[N];
vector<P> brdgs;

void dfs(int cur, int par) {
    vis[cur] = low[cur] = tme++;
    for (auto x : gr[cur]) {
        if (!vis[x]) {
            dfs(x, cur);
            chld[cur]++;
            low[cur] = min(low[cur], low[x]);
            if (par && low[x] >= vis[cur]) {
                art_p.pb(cur);
            }
            if (low[x] > vis[cur]) {
                brdgs.pb({cur, x});
            }
        }
        else if (x != par) {
            low[cur] = min(low[cur], vis[x]);
        }
    }
    if (par == 0 && chld[cur] > 1) art_p.pb(cur); // for root
}


int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        tme = 1;
        dfs(1, 0);
        sort(art_p.begin(), art_p.end());
        sort(brdgs.begin(), brdgs.end());
        cout << art_p.size() << '\n';
        for (auto x : art_p) {
            cout << x << " ";
        } cout << '\n';
        cout << brdgs.size() << '\n';
        for (auto x : brdgs) {
            cout << x.F << " " << x.S << "\n";
        }
    }
}