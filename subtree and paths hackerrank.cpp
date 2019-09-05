// subtrees and paths hackerrank
// although giving tle in few cases
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

const int N = 100005, M = 18;
int ptr = 0, chain_no = 0;

vector<P> gr[N], edges;
int subsize[N], dep[N], Par[N][M], tme = 0, tin[N], tout[N];
int chain_head[N], chain_Ind[N], chain_size[N];
int Base_array[N], pos_in_Base[N];

class segmenttreewithlazy
{
public:
    int st[N * 4], lazy[N * 4];

    void update_range(int start, int end, int l, int r, int val, int node) {
        if (lazy[node] != 0) {
            //update lazy node and forward value to children
            st[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > end || end < l || start > r) { //no overlap
            return ;
        }
        if (start >= l && end <= r) { //complete overlap
            //update stnode node and forward value to children
            st[node] += val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return ;
        }
        int mid = (start + end) / 2;
        update_range(start, mid, l, r, val, node * 2 + 1);
        update_range(mid + 1, end, l, r, val, node * 2 + 2);
        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }

    int query(int start, int end, int l, int r, int node) {
        if (start > end || end < l || start > r) {
            return INT_MIN;
        }
        if (lazy[node] != 0) {
            //update lazy node and forward value to children
            st[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start >= l && end <= r) {
            return st[node];
        }
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, end, l, r, node * 2 + 2);
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
    tin[cur] = ++tme;
    for (auto x : gr[cur]) {
        if (x.F != par) {
            dfs(x.F, cur);
            subsize[cur] += subsize[x.F];
        }
    }
    tout[cur] = tme;
}

void edge() {
    int x, y, w = 0;
    cin >> x >> y;
    gr[x].pb({y, w});
    gr[y].pb({x, w});
    edges.pb({x, y});
}

int query_up(int u, int v) {
    int uchain = chain_Ind[u], vchain = chain_Ind[v], ans = INT_MIN;
    while (1) {
        uchain = chain_Ind[u];
        if (uchain == vchain) {
            if (u == v) {
                ans = max(ans, tr.query(0, ptr - 1, pos_in_Base[u], pos_in_Base[u], 0));
                break;
            }
            ans = max(ans, tr.query(0, ptr - 1, pos_in_Base[v], pos_in_Base[u], 0));
            break;
        }
        else {
            ans = max(ans, tr.query(0, ptr - 1, pos_in_Base[chain_head[uchain]], pos_in_Base[u], 0));
            u = Par[chain_head[uchain]][0];
        }
    }
    return ans;
}

bool is_ancestor(int u, int v) {
    //is u ancestor of v?
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void query_update(int u, int k) {
    int uchain = chain_Ind[u];
    for (int i = 0; i <= chain_no; i++) {
        int v = chain_head[i];
        int vchain = chain_Ind[v];
        if (uchain == vchain) {
            tr.update_range(0, ptr - 1, pos_in_Base[u], pos_in_Base[v] + chain_size[i] - 1, k, 0);
        }
        else if (is_ancestor(u, v)) {
            tr.update_range(0, ptr - 1, pos_in_Base[v], pos_in_Base[v] + chain_size[i] - 1, k, 0);
        }
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
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
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            if (s == "max") {
                int u, v;
                cin >> u >> v;
                int lca = LCA(u, v);
                cout << max(query_up(u, lca), query_up(v, lca)) << '\n';
            }
            else {
                int u;
                cin >> u >> k;
                query_update(u, k);
            }
        }
    }
}