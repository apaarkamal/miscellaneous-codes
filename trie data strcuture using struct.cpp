#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

const ll N = 100005;

struct Trie
{
    struct Trie *nxt[26];
};


Trie* head;

void insert(string s, string s1) {
    Trie *cur = head;
    for (ll i = 0; i < s.size(); i++) {
        ll cnt = s[i] - 'a';
        if (cur->nxt[cnt] == NULL) {
            cur->nxt[cnt] = new Trie();
        }
        cur = cur->nxt[cnt];
    }
}

ll give(string s) {
    Trie *cur = head;
    string final_string;
    for (ll i = 0; i < s.size(); i++) {
        ll cnt = s[i] - 'a';
        if (cur->nxt[cnt] == NULL) {
            return -1;
        }
        cur = cur->nxt[cnt];
    }
    return cntvowel(final_string);
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        head = new Trie();
        cin >> n;
        for (i = 0; i < n; i++) {
            string s, s1;
            cin >> s >> s1;
            insert(s, s1);
        }
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            cout << give(s) << '\n';
        }

    }
}