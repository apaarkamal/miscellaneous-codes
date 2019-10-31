// Author : Apaar
// Built  : 28-10-2019 16:18:07
// http://codeforces.com/contest/1251/problem/E2
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

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const int N = 100005;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        vpi a(n);
        vi v[n];
        for (i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
            v[a[i].F].pb(a[i].S);
        }
        int sm = n;
        int have = 0;
        priority_queue<int, vi, greater<int>> Q;
        for (i = n - 1; i >= 0 ; i--) {
            sm -= v[i].size();
            int need = i - sm;
            for (auto x : v[i]) Q.push(x);
            // db(i, have, need, ans);
            while (have < need) {
                ans += Q.top();
                Q.pop();
                have++;
            }
        }
        cout << ans << '\n';
    }
}