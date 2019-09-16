#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 200005, M = 11;

map<int, int> mp[M];

int len_num(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> k;
        int a[n];
        int pow10[M];
        pow10[0] = 1;
        for (i = 1; i < M; i++) {
            pow10[i] = pow10[i - 1] * 10;
            pow10[i] %= k;
        }
        for (i = 0; i < n; i++) {
            cin >> a[i];
            mp[len_num(a[i])][a[i] % k]++;
        }
        for (i = 0; i < n; i++) {
            for (j = 1; j < M; j++) {
                int val = ((a[i] % k) * pow10[j] ) % k;
                int need = (k - val ) % k;
                ans += mp[j][need];
            }
        }
        for (i = 0; i < n; i++) {
            int len = len_num(a[i]);
            int num = ((a[i] % k) * (pow10[len] % k)) % k;
            num += a[i];
            num %= k;
            if (num == 0) ans--;
        }
        cout << ans;
    }
}