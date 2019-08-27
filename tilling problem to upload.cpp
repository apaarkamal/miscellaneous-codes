#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005;
int mod=1e9+7;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        int dp[n+1]={};
        dp[0]=1;
        dp[1]=1;
        for(i=2;i<=n;i++){
            dp[i]=dp[i-1];
            if(i-m>=0){
                dp[i]+=dp[i-m];
            } 
            dp[i]%=mod;              
        }
        cout<<dp[n]<<'\n';
    }
}