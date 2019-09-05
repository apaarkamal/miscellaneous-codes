// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/special-pairs-7/description/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

void the_martian() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}


#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


const int N = (1 << 21), M = 21;

int dp[N];

const int K = (1 << 21) - 1;

int32_t main()
{
    the_martian();
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, sum = 0;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
            dp[a[i]]++;
        }
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                if ((1 << i)&j) {
                    dp[j] += dp[(1 << i)^j];
                }
            }
        }
        for (i = 0; i < n; i++) {
            ans += dp[(K ^ a[i])];
        }
        cout << ans << '\n';
        for (i = 0; i < N; i++) {
            dp[i] = 0;
        }
    }
}