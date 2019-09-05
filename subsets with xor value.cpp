#include <bits/stdc++.h>
#define lli long long int
#define plli pair<lli,lli>
#define mp make_pair
#define pb push_back
#define MAX 100005
#define M 1000000007
#define pf printf
#define sf scanf

using namespace std;

int main()
{
    int n;
    cin >> n;
    lli a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    lli max_ele = -1;

    for (int i = 0; i < n; i++)
        if (a[i] > max_ele)
            max_ele = a[i];

    int m = (1 << (int)(log2(max_ele) + 1) ) - 1;
    lli dp[n + 1][m + 1]; //dp[i][j] equals to the number of subsets
    //having XOR value j from subsets of arr[0…i-1].
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; //no. of subset with 0 xor value=1(empty set)

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ a[i - 1]];

    cout << dp[n][0] - 1 << endl;


    //  cout<<c<<endl;
}