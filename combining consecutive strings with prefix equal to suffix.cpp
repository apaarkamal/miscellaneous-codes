// https://codeforces.com/contest/1200/problem/E
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 2000005;
int lps[N];

int buildlpsarray(string pat) {
    int m = pat.size(), i = 0, j = 0;
    lps[0] = 0;
    for (int i = 0; i < m; i++) {
        lps[i] = 0;
    }
    i = 1;
    while (i < m) {
        if (pat[i] == pat[j]) {
            lps[i] = j + 1;
            j++; i++;
        }
        else {
            if (j == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }
    }
    return lps[m - 1];
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        string s[n];
        for (i = 0; i < n; i++) {
            cin >> s[i];
        }
        string anss;
        anss = s[0];
        for (i = 1; i < n; i++) {
            int st, ln;
            st = max(0ll, (int)anss.size() - (int)s[i].size());
            ln = min((int)anss.size(), (int)s[i].size());
            string ss = s[i].substr() + '#' + (anss.substr(st, ln));
            cnt = buildlpsarray(ss);
            anss += (ss.substr(cnt, (int)s[i].size() - cnt));
        }
        cout << anss;
    }
}