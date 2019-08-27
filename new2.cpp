#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;

struct segmenttree {
    vector<int> st;
    void init(int _n) {
        st.clear();
        st.resize(4 * _n);
    }
    void build(int l, int r, int node) {
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1);
        build(mid + 1, r, node * 2 + 2);
        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }

    void update(int l, int r, int indup, int val, int node) {
        if (l == r) {
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
            return INT_MIN;
        }
        if (si >= l && se <= r) {
            return st[node];
        }
        int mid = (si + se) / 2;
        int q1 = query(si, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, se, l, r, node * 2 + 2);
        return max(q1, q2);
    }
};
segmenttree tree[N];
int sz[N], res[N], mx[N], n, m;
vector<int> pos[N];

int give(int row, int pos) {
    int mn, mx, ret;
    if (pos < sz[row]) {
        mn = max(0ll, pos - (m - sz[row])), mx = pos;
        if ((m - 1) - pos >= sz[row]) ret = 0;
        else ret = INT_MIN;
    }
    else {
        pos = sz[row] - (m - pos);
        mn = pos, mx = max(sz[row] - 1, pos + (m - sz[row]));
        if (pos >= sz[row]) ret = INT_MIN;
        else ret = 0;
    }
    return max(ret, tree[rGow].query(0, sz[row] - 1, mn, mx, 0));
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            cin >> sz[i];
            tree[i].init(sz[i]);
            for (j = 0; j < sz[i]; j++) {
                int x;
                cin >> x;
                mx[i] = max(mx[i], x);
                tree[i].update(0, sz[i] - 1, j, x, 0);
            }
            for (j = 0; j < sz[i]; j++) pos[j].pb(i);
            for (j = max(sz[i], (m - sz[i])); j < m; j++) pos[j].pb(i);
        }
        for (i = 0; i < n; i++) {
            ans += mx[i];
        }
        for (i = 0; i < m; i++) {
            res[i] = ans;
            for (auto x : pos[i]) {
                res[i] -= mx[x];
                res[i] += give(x, i);
            }
        }
        for (i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
    }
}