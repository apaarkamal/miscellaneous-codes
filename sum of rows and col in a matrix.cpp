#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    int n, m, i, j;
    cin >> n >> m;
    int a[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int rowsum[n], colsum[m];
    for (i = 0; i < n; i++) {
        rowsum[i] = 0;
    }
    for (i = 0; i < m; i++) {
        colsum[i] = 0;
    }
    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = 0; j < m; j++) {
            sum += a[i][j];
        }
        rowsum[i] = sum;
    }
    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
        colsum[j] = sum;
    }
    for (i = 0; i < n; i++) {
        cout << "rownum " << i << " " << rowsum[i] << '\n';
    }
    for (i = 0; i < m; i++) {
        cout << "colnum " << i << " " << colsum[i] << '\n';
    }
}
