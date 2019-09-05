#include<bits/stdc++.h>

using namespace std;

int grid[10][10], vis[10][10], n, ans = -1, sum = 0, N = 10;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, -2, 2, -1, 1};

void input_grid() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) sum++;
            vis[i][j] = 0;
        }
    }
}

void knight(int x, int y, int cnt) {
    ans = max(ans, cnt);
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < N && yy >= 0 && yy < N && grid[xx][yy]) {
            grid[xx][yy] = 0;
            knight(xx, yy, cnt + 1);
            grid[xx][yy] = 1;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    cin >> n;
    input_grid();
    int i, j;
    grid[0][0] = 0;
    knight(0, 0, 1);
    cout << sum - ans;
}
