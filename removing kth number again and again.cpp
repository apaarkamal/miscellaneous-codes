#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--)
  {
    int n; cin >> n;
    int k;
    cin >> k;

    //int cn[n+1];
    // memset(cn,0,sizeof(cn));


    int ans = 1;


    for (int i = 2; i <= n; i++)
    {
      ans += k;
      while (ans > i)
        ans = ans - i;

      // cout<<i<<" "<<ans<<endl;
    }
    cout << ans << endl;

  }
}
