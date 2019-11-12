/* Apaar */
// https://codeforces.com/contest/359/problem/D
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct sparse_table {
    vector<vector<int>> mat;// 0 based indexing
    int n, m; // size and log
    vector<int> p2;//log2
    void init(int _n, int _m) {
        n = _n; m = _m;
        mat.resize(n); p2.resize(n + 1);
        for (int i = 0; i < n; i++) mat[i].resize(m);
        for (int i = 2; i <= n; i++) p2[i] = p2[i / 2] + 1;
    }
    void build() {
        int i, j;
        for (i = 0; i < n; i++) mat[i][0] = a[i];
        for (j = 1; j < m; j++) {
            for (i = 0; i + (1 << j) <= n; i++) {
                mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int pw = p2[r - l];
        return min(mat[l][pw], mat[r - (1 << pw) + 1][pw]);
    }
} table;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

    }
}