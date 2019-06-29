#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll x[105],y[105],vis[105]={};
void dfs(ll cur,ll n){
    vis[cur]++;
    for(ll i=0;i<n;i++){
        if(!vis[i]&&((x[i]==x[cur])||(y[i]==y[cur]))){
            dfs(i,n);
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
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        for(i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,n);
                ans++;
            }
        }
        cout<<ans-1;
    }
}
