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

const int N = 10005, M = 14;
int ptr = 0, chain_no = 0;

vector<P> gr[N], edges;
int subsize[N], dep[N], Par[N][M];
int chain_head[N], chain_Ind[N], chain_size[N];
int Base_array[N], pos_in_Base[N];

class segmenttree
{
public:
    int st[N * 4];
    void build(int l, int r, int node) {
        if (l == r) {
            st[node] = Base_array[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1);
        build(mid + 1, r, node * 2 + 2);
        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }

    void update(int l, int r, int indup, int val, int node) {
        if (l == r) {
            Base_array[l] = val;
            st[node] = val;
            return;
        }
        else {
            int mid = (l + r) / 2;
            if (indup >= l && indup <= mid) {
                update(l, mid, indup, val, node * 2 + 1);
            }
            else {
                update(mid + 1, r, indup, val, node * 2 + 2);
            }
            st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        }
    }

    int query(int si, int se, int l, int r, int node) {
        if (se < l || si > r || l > r) {
            return -1;
        }
        if (si >= l && se <= r) {
            return st[node];
        }
        int mid = (si + se) / 2;
        int q1 = query(si, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, se, l, r, node * 2 + 2);
        return max(q1, q2);
    }
} tr;

void HLD(int cur, int par, int weight) {
    if (chain_head[chain_no] == 0) {
        chain_head[chain_no] = cur;
    }
    chain_Ind[cur] = chain_no;
    pos_in_Base[cur] = ptr;
    Base_array[ptr++] = weight;
    chain_size[chain_no]++;

    int sp_chld = -1, w_sp_chld;
    for (auto x : gr[cur]) {
        if (x.F != par && (sp_chld == -1 || subsize[x.F] > subsize[sp_chld])) {
            sp_chld = x.F;
            w_sp_chld = x.S;
        }
    }
    if (sp_chld != -1) {
        HLD(sp_chld, cur, w_sp_chld);
    }
    for (auto x : gr[cur]) {
        if (x.F != par && x.F != sp_chld) {
            chain_no++;
            HLD(x.F, cur, x.S);
        }
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int diff = dep[u] - dep[v];
    for (int i = M - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            u = Par[u][i];
        }
    }
    if (u == v) return v;
    for (int i = M - 1; i >= 0; i--) {
        if (Par[u][i] != Par[v][i]) {
            u = Par[u][i];
            v = Par[v][i];
        }
    }
    return Par[u][0];
}


void cal_sparse_matrix(int cur, int par) {
    Par[cur][0] = par;
    for (int i = 1; i < M; i++) {
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }
    for (auto x : gr[cur]) {
        if (par != x.F) {
            cal_sparse_matrix(x.F, cur);
        }
    }
}

void dfs(int cur, int par) {
    subsize[cur] = 1;
    dep[cur] = dep[par] + 1;
    for (auto x : gr[cur]) {
        if (x.F != par) {
            dfs(x.F, cur);
            subsize[cur] += subsize[x.F];
        }
    }
}

void edge() {
    int x, y, w;
    cin >> x >> y >> w;
    gr[x].pb({y, w});
    gr[y].pb({x, w});
    edges.pb({x, y});
}

int query_up(int u, int v) {
    int uchain = chain_Ind[u], vchain = chain_Ind[v], ans = 0;
    while (1) {
        uchain = chain_Ind[u];
        if (uchain == vchain) {
            if (v == u) break;
            ans = max(ans, tr.query(0, ptr - 1, pos_in_Base[v] + 1, pos_in_Base[u], 0));
            break;
        }
        else {
            ans = max(ans, tr.query(0, ptr - 1, pos_in_Base[chain_head[uchain]], pos_in_Base[u], 0));
            u = Par[chain_head[uchain]][0];
        }
    }
    return ans;
}

void clr(int n) {
    edges.clear();
    for (int i = 0; i <= n; i++) {
        gr[i].clear();
        subsize[i] = 0;
        dep[i] = 0;
        chain_head[i] = 0;
        chain_Ind[i] = 0;
        chain_size[i] = 0;
        chain_size[i] = 0;
        Base_array[i] = 0;
        pos_in_Base[i] = 0;
        for (int j = 0; j < M; j++) {
            Par[i][j] = 0;
        }
    }
    ptr = 0;
}

int32_t main()
{
    the_martian();
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        for (i = 1; i < n; i++) {
            edge();
        }
        ptr = 0;
        chain_no = 0;
        dfs(1, 0);
        cal_sparse_matrix(1, 0);
        HLD(1, 0, 0);
        tr.build(0, ptr - 1, 0);

        while (1) {
            string s;
            cin >> s;
            if (s[0] == 'Q') {
                int u, v;
                cin >> u >> v;
                int lca = LCA(u, v);
                cout << max(query_up(u, lca), query_up(v, lca)) << '\n';
            }
            else if (s[0] == 'C') {
                cin >> j >> k;
                j--;
                int u = edges[j].F, v = edges[j].S;
                if (Par[u][0] != v) swap(u, v);
                tr.update(0, ptr - 1, pos_in_Base[u], k, 0);
            }
            else {
                break;
            }
        }
        clr(n);
    }
}