// http://codeforces.com/contest/348/problem/A
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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
        cin >> n;
        ll a[n];
        ll mx = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
            sum += a[i];
        }
        cout << max(mx, (sum + n - 2) / (n - 1));
    }
}
