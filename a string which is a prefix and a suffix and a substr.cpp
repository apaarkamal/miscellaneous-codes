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

const int N = 1000005;
string s;
int lps[N], pos[N];

void buildlpsarray() {
    int m = s.size(), i = 0, j = 0;
    lps[0] = 0;
    i = 1;
    while (i < m) {
        if (s[i] == s[j]) {
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
}

inline void check(int len) {
    if (len <= 0) return;
    if (pos[len] == -1) return;
    cout << s.substr(0, len);
    exit(0);
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
        int i, j, a, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> s;
        n = s.size();
        buildlpsarray();
        memset(pos, -1, sizeof(pos));
        for (i = 1; i < n - 1; i++) {
            pos[lps[i]] = i;
            db(i, lps[i], pos[i]);
        }
        for (i = 0; i < n; i++) {
            cout << pos[i] << " ";
        }
        int len = lps[n - 1];
        while (len > 0) {
            // db(len);
            check(len);
            len = lps[len - 1];
        }
        cout << "Just a legend";
    }
}