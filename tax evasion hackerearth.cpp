#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1005;
int a[N];

const int NN = 5005, MM = 500005;
struct MaxFlow {
    vector<int> gr[NN];
    struct Edge {
        int x, y, w;
    } edges[MM];
    int source, sink, flow, n, ec, Level[NN], Q[NN], PV[NN];
    void init(int sz, int SRC, int SN) {
        n = sz, source = SRC, sink = SN, flow = ec = 0;
        for (int i = 0; i <= n; i++) gr[i].clear();
    }
    void add_edge(int x, int y, int w) {
        gr[x].pb(ec);
        edges[ec++] = {x, y, w};
        gr[y].pb(ec);
        edges[ec++] = {y, x, w}; // for undirected replace 0 with w
    }
    int BlockFlow(int cur, int cnt) { //dfs
        if (cur == sink) return cnt;
        for (int &i = PV[cur]; i >= 0; i--) {
            int cur_e = gr[cur][i];
            if (edges[cur_e].w && Level[edges[cur_e].y] == Level[cur] + 1) {
                if (int val = BlockFlow(edges[cur_e].y, min(cnt, edges[cur_e].w))) {
                    edges[cur_e].w -= val;
                    edges[cur_e ^ 1].w += val;
                    return val;
                }
            }
        }
        return 0;
    }
    bool GetLevel() {// bfs
        int head = 0, tail = 0, i;
        for (i = 0; i <= n; i++)Level[i] = -1;
        Q[++tail] = source; Level[source] = 0;
        while (head < tail) {
            int cur = Q[++head];
            for (auto &t : gr[cur]) {
                if (edges[t].w && Level[edges[t].y] == -1) {
                    Level[edges[t].y] = Level[cur] + 1;
                    Q[++tail] = edges[t].y;
                }
            }
        }
        return Level[sink] != -1;
    }
    void Dinic() {
        int i, t;
        flow = 0;
        while (GetLevel()) {
            for (i = 0; i <= n; i++) PV[i] = gr[i].size() - 1;
            while (t = BlockFlow(source, 1e18)) {
                flow += t;
            }
        }
    }
} G;
// dont forget to initialise

bool check(int x, int n) {
    G.init(n + 2, 0, n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            G.add_edge(i, n + 1, -a[i]);
        }
        else {
            G.add_edge(0, i, a[i]);
            cnt += a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            G.add_edge(i, j, x);
        }
    }
    G.Dinic();
    return G.flow == cnt;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, n, k, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        int lf = 0, rt = 1e10;
        while (lf < rt) {
            int mid = (lf + rt) / 2;
            if (check(mid, n)) {
                rt = mid;
            }
            else {
                lf = mid + 1;
            }
        }
        cout << lf;
    }
}