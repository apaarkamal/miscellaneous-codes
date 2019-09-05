//DCOWS spoj
#include<bits/stdc++.h>
using namespace std;
long long dp[5001][5001], sel;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int bulls[5001] = {0}, cows[5001] = {0};
    for (int i = 1; i <= n; i++)
        scanf("%d", &bulls[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &cows[i]);
    sort(bulls, bulls + n + 1);
    sort(cows, cows + m + 1);
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 9999999999999;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(bulls[i] - cows[j]));
        }
    }
    printf("%lld\n", dp[n][m]);
    return 0;
}