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

const int N = 5005;

vector<int> v[N];
int a[N][N];
string s[N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            cin >> s[i];
            for (j = 0; j < m; j++) {
                a[i][j] = (s[i][j] == '1');
            }
        }
        for (i = 0; i < n; i++) {
            cnt = 0;
            for (j = m - 1; j >= 0; j--) {
                if (a[i][j]) cnt++;
                else cnt = 0;
                a[i][j] = cnt;
            }
        }
        for (j = 0; j < m; j++) {
            for (i = 0; i < n; i++) {
                v[j].pb(a[i][j]);
            }
        }
        for (i = 0; i < m; i++) {
            sort(v[i].begin(), v[i].end());
        }
        for (j = 0; j < m; j++) {
            for (i = 0; i < n; i++) {
                ans = max(ans, v[j][i] * (n - i));
            }
        }
        cout << ans;
    }
}