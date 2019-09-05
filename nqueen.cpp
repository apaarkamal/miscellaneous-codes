#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll grid[100][100], z = 0;
bool issafe(ll row, ll col, ll n) {
  ll i, j;
  for (j = 0; j < n; j++) {
    if (grid[row][j]) {
      return false;
    }
  }
  for (i = 0; i < n; i++) {
    if (grid[i][col]) {
      return false;
    }
  }
  i = row; j = col;
  while (i >= 0 && j >= 0) {
    if (grid[i][j]) {
      return false;
    }
    i--; j--;
  }
  i = row; j = col;
  while (i >= 0 && j < n) {
    if (grid[i][j]) {
      return false;
    }
    i--; j++;
  }
  return true;
}
void nqueen(ll row, ll n) {
  if (row == n) {
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        if (grid[i][j]) {
          cout << "Q ";
        }
        else {
          cout << ". ";
        }
      } cout << '\n';
    }
    cout << '\n';
    z++;
    return;
    // exit(0);
  }
  for (ll col = 0; col < n; col++) {
    if (issafe(row, col, n)) {
      grid[row][col] = 1;
      nqueen(row + 1, n);
      grid[row][col] = 0;
    }
  }
}
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
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        grid[i][j] = 0;
      }
    }
    nqueen(0ll, n);
    cout << z;
  }
}