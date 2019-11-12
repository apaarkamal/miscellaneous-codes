/* Apaar $axena */
// https://codeforces.com/contest/282/problem/E
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct node {
    node* nxt[2];
    node() {
        nxt[0] = nxt[1] = NULL;
    }
};

node* root;

void insert(int x) {
    node* cur = root;
    for (int i = 42; i >= 0; i--) {
        int bit = (x >> i) & 1ll;
        if (cur->nxt[bit] == NULL) {
            cur->nxt[bit] = new node();
        }
        cur = cur->nxt[bit];
    }
}

int find_max(int x) {
    node* cur = root;
    int ans = 0;
    for (int i = 42; i >= 0; i--) {
        int bit = (x >> i) & 1ll;
        if (bit) {
            if (cur->nxt[0]) {
                ans += (1ll << i);
                cur = cur->nxt[0];
            }
            else {
                cur = cur->nxt[1];
            }
        }
        else {
            if (cur->nxt[1]) {
                ans += (1ll << i);
                cur = cur->nxt[1];
            }
            else {
                cur = cur->nxt[0];
            }
        }
    }
    return ans;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int a[n + 1], pref[n + 1];
        pref[0] = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] ^ a[i];
        }
        int suf = 0;
        root = new node();
        insert(suf);
        for (i = n; i >= 0 ; i--) {
            cnt = find_max(pref[i]);
            ans = max(ans, cnt);
            suf ^= a[i];
            insert(suf);
        }
        cout << ans;
    }
}