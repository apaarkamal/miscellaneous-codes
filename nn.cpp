#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(x) cout <<#x<<": "<<x<<'\n';

const int N = 100005;

int32_t main()
{
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  // int t;cin>>t;while(t--)
  {
    string s; cin >> s;
    int c = 0;
    for (int i = 0; i < n + 1; i++)
    {
      int no = s[i] - '0';
      int nx = s[i + 1] - '0';
      c = no + nx;
      if (c == 0) s[i + 1] = '0';
      c = 1;
    }

  }
}