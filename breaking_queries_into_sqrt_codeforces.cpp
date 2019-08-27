// https://codeforces.com/contest/1207/problem/F
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=500005,M=sqrt(N); 

int dp[M][M],a[N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>m;
        while(m--){
            int t,x,y;
            cin>>t>>x>>y;
            if(t==1){
                a[x]+=y;
                for(i=1;i<M;i++){
                    dp[i][x%i]+=y;          
                }
            }
            else if(x<M){
                cout<<dp[x][y]<<'\n';
            }
            else{
                ans=0;
                for(i=y;i<N;i+=x){
                    ans+=a[i];
                }
                cout<<ans<<'\n';           
            }
        }

    }
}