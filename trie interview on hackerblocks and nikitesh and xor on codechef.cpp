// https://www.codechef.com/problems/REBXOR
#include<bits/stdc++.h>

using namespace std;

// #define int long long int
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

const int N = 400005, M = 30;

struct Node {
    int lf, rt, cnt;
};
Node trie[N * M * 4];
int ptr = 1, root[N];
int a[N], lbest[N], rbest[N], prexor[N];

int insert(int prev, int num) {
    int cur = ptr++;
    int temp = cur;
    trie[cur] = trie[prev];
    for (int i = M - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            trie[cur].rt = ptr++;
            trie[trie[cur].rt] = trie[trie[prev].rt];
            trie[trie[cur].rt].cnt = trie[trie[prev].rt].cnt + 1;
            cur = trie[cur].rt;
            prev = trie[prev].rt;
        }
        else {
            trie[cur].lf = ptr++;
            trie[trie[cur].lf] = trie[trie[prev].lf];
            trie[trie[cur].lf].cnt = trie[trie[cur].lf].cnt + 1;
            cur = trie[cur].lf;
            prev = trie[prev].lf;
        }
    }
    return temp;
}

int maxxor(int prev, int cur, int num) {
    int ans = 0;
    for (int i = M - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            // db(num,ans,i);
            // db(trie[trie[prev].lf].cnt,trie[trie[cur].lf].cnt);
            if (trie[trie[prev].lf].cnt < trie[trie[cur].lf].cnt) {
                ans += (1 << i);
                prev = trie[prev].lf;
                cur = trie[cur].lf;
            }
            else {
                prev = trie[prev].rt;
                cur = trie[cur].rt;
            }
        }
        else {
            if (trie[trie[prev].rt].cnt < trie[trie[cur].rt].cnt) {
                ans += (1 << i);
                prev = trie[prev].rt;
                cur = trie[cur].rt;
            }
            else {
                prev = trie[prev].lf;
                cur = trie[cur].lf;
            }
        }
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        trie[0].lf = trie[0].rt = trie[0].cnt = root[0] = a[0] = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            prexor[i] = prexor[i - 1] ^ a[i];
            root[i] = insert(root[i - 1], prexor[i]);
            lbest[i] = max({lbest[i - 1], maxxor(0, root[i], prexor[i]), prexor[i] ^ 0});
        }
        reverse(a + 1, a + n + 1);
        trie[0].lf = trie[0].rt = trie[0].cnt = root[0] = a[0] = 0;
        for (i = 0; i <= ptr; i++) {
            trie[i].lf = trie[i].rt = trie[i].cnt = 0;
        }
        for (i = 0; i < N; i++) {
            prexor[i] = 0;
            root[i] = 0;
        }
        ptr = 1;
        for (i = 1; i <= n; i++) {
            prexor[i] = prexor[i - 1] ^ a[i];
            root[i] = insert(root[i - 1], prexor[i]);
            rbest[i] = max({rbest[i - 1], maxxor(0, root[i], prexor[i]), prexor[i] ^ 0});
        }
        reverse(rbest + 1, rbest + n + 1);
        for (i = 1; i <= n; i++) {
            ans = max(ans, lbest[i] + rbest[i + 1]);
            // db(lbest[i],rbest[i]);
        }
        cout << ans;
    }
}