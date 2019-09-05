// https://www.codechef.com/problems/MCO16404
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

const int N = 300005, M = 33;
int a[N];
V<V<int>> query[N];

struct trie {
    struct trie *lf = NULL, *rt = NULL;
    int prev = -1;
};

trie* head;

void insert(int num, int ind) {
    trie *cur = head;
    for (int i = M - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            if (cur->rt == NULL) {
                cur->rt = new trie();
            }
            cur = cur->rt;
            cur->prev = max(cur->prev, ind);
        }
        else {
            if (cur->lf == NULL) {
                cur->lf = new trie();
            }
            cur = cur->lf;
            cur->prev = max(cur->prev, ind);
        }
    }
}

int give(int l, int num) {
    trie *cur = head;
    int ans = 0;
    for (int i = M - 1; i >= 0; i--) {
        int best;
        if ((num >> i) & 1) best = 0;
        else best = 1;
        if (best && cur->rt == NULL) {
            best ^= 1;
        }
        else if (!best && cur->lf == NULL) {
            best ^= 1;
        }
        if (best && cur->rt->prev < l) {
            best ^= 1;
        }
        else if (!best && cur->lf->prev < l) {
            best ^= 1;
        }
        ans += best * (1 << i);
        if (best) cur = cur->rt;
        else cur = cur->lf;
    }
    return ans;
}

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
        int i, j, k, n, m, cnt = 0, sum = 0, z = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        head = new trie();
        int ans[N];
        cin >> m;
        for (i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            l--; r--;
            query[r].pb({l, x, i});
        }
        for (i = 0; i < n; i++) {
            insert(a[i], i);
            for (auto x : query[i]) {
                ans[x[2]] = give(x[0], x[1])^x[1];
            }
        }
        for (i = 0; i < m; i++) {
            cout << ans[i] << '\n';
        }
    }
}