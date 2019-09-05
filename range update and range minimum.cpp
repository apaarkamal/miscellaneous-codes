// https://www.hackerearth.com/problem/algorithm/range-update-range-max-queries/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define IOS

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


const int N = 100005;

void the_martian() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}

int a[N];

class segmenttreewithlazy
{
public:
    int st[N * 4], lazy[N * 4];
    void build(int start, int end, int node) {
        if (start == end) {
            st[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, node * 2 + 1);
        build(mid + 1, end, node * 2 + 2);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

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
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    int query(int start, int end, int l, int r, int node) {
        if (start > end || end < l || start > r) {
            return INT_MAX;
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
        return min(q1, q2);
    }
} tree;



int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        tree.build(0, n - 1, 0);
        while (m--) {
            char ch;
            cin >> ch;
            if (ch == 'q') {
                int l, r;
                cin >> l >> r;
                cout << tree.query(0, n - 1, l - 1, r - 1, 0) << '\n';
            }
            else {
                int l, r, val;
                cin >> l >> r >> val;
                tree.update_range(0, n - 1, l - 1, r - 1, val, 0);
            }
        }
    }
}