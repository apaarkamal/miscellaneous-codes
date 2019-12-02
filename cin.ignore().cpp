#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0;
        cin >> n;
        char s[n];
        map<char, int> mp;
        for (i = 0; i < n; i++) {
            cin >> s[i];
            mp[s[i]]++;
        }
        string t;
        cin.ignore(256, '\n');
        getline(cin, t);
        // cout << t << '\n';
        m = t.size();
        for (i = 0; i < m; i++) {
            if (mp[t[i]]) ans++;
        }
        cout << ans << '\n';
    }
}