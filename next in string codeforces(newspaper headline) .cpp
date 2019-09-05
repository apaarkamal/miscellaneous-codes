// http://codeforces.com/problemset/problem/91/A
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const ll N = 10005;
ll nxt[N][26] = {};

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
        string s, t;
        cin >> s >> t;
        n = s.size();
        m = t.size();
        ll cnts[26] = {}, cntt[26] = {};
        for (i = 0; i < n; i++) {
            cnts[s[i] - 'a']++;
        }
        for (j = 0; j < m; j++) {
            cntt[t[j] - 'a']++;
        }
        for (i = 0; i < 26; i++) {
            if (cntt[i] != 0 && cnts[i] == 0) {
                cout << -1;
                return 0;
            }
        }
        for (i = 0; i < 26; i++) {
            j = 0, k = 0;
            if (s.find('a' + i) != -1) {
                for (j = 0; j < n; j++) {
                    if (k == j) {
                        k++;
                        k %= n;
                    }
                    while ((s[k] - 'a') != i) {
                        k++;
                        k %= n;
                    }
                    nxt[j][i] = k;
                }
            }
        }
        cnt = n - 1;
        for (i = 0; i < m; i++) {
            ll cur = t[i] - 'a';
            if (nxt[cnt][t[i] - 'a'] <= cnt) {
                ans++;
            }
            cnt = nxt[cnt][t[i] - 'a'];
        }
        cout << ans;
    }
}