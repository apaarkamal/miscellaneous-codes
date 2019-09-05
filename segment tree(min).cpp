#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

const int N = 100005;

int a[N];

struct segmenttree {
    vector<int> st;
    void init(int _n) {
        st.clear();
        st.resize(4 * _n);
    }
    void build(int l, int r, int node) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1);
        build(mid + 1, r, node * 2 + 2);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    void update(int l, int r, int indup, int val, int node) {
        if (l == r) {
            a[l] = val;
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
            st[node] = min(st[2 * node + 1], st[2 * node + 2]);
        }
    }

    int query(int si, int se, int l, int r, int node) {
        if (se < l || si > r || l > r) {
            return INT_MAX;
        }
        if (si >= l && se <= r) {
            return st[node];
        }
        int mid = (si + se) / 2;
        int q1 = query(si, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, se, l, r, node * 2 + 2);
        return min(q1, q2);
    }
} tree;

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
            cin >> a[i];
        }
    }
}