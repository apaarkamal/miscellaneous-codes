// https://codeforces.com/contest/1092/problem/F
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

const int N=200005;

int val[N],dp[N],sum[N],f=0;
vector<int> gr[N];

void dfs(int cur,int par){
    dp[cur]=0;
    sum[cur]=val[cur];
    for(auto x:gr[cur]){
        if(x!=par){
            dfs(x,cur);
            dp[cur]+=sum[x];
            dp[cur]+=dp[x];
            sum[cur]+=sum[x];
        }   
    }
}

void dfs1(int cur,int par,int res){
    f=max(f,res);
    for(auto x:gr[cur]){
        if(x!=par){
            int temp=res-sum[x]+(sum[cur]-sum[x]);
            sum[cur]-=sum[x];
            sum[x]+=sum[cur];
            dfs1(x,cur,temp);
            sum[x]-=sum[cur];
            sum[cur]+=sum[x];
        }   
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>val[i+1];
        }
        for(i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            gr[x].pb(y);                
            gr[y].pb(x);                
        }
        dfs(1,0);
        ans=dp[1];
        dfs1(1,0,ans);
        cout<<f;
    }
}