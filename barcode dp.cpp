// http://codeforces.com/problemset/problem/225/C
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
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;    
        ll x,y;
        cin>>n>>m>>x>>y;
        string s[n];
        for(i=0;i<n;i++){
          cin>>s[i];
        }
        ll black[m+1]={},white[m+1]={};
        for(j=0;j<m;j++){
          for(i=0;i<n;i++){
            if(s[i][j]=='#'){
              cnt++;
            }
            else{
              sum++;
            }
          }
          black[j+1]=cnt;
          white[j+1]=sum;
        }
        ll dp[m+1][2];
        dp[0][0]=dp[0][1]=0;
        for(j=1;j<=m;j++){
          dp[j][0]=dp[j][1]=1e10;
          for(i=x;i<=y;i++){
            if(j-i>=0){
              dp[j][1]=min(dp[j][1],white[j]-white[j-i]+dp[j-i][0]);
              dp[j][0]=min(dp[j][0],black[j]-black[j-i]+dp[j-i][1]);
            }
          }
        }
        cout<<min(dp[m][0],dp[m][1]);
    }
}
