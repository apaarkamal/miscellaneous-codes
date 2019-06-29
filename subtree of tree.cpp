#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long int
using namespace std;
const ll N=100005;
vector<ll> v[N];
ll vis[N];
ll in[N],out[N],tt=0;
void dfs(ll cur){
    vis[cur]++;
    in[cur]=tt;
    tt++;
    for(ll x:v[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    out[cur]=tt;
    tt++;
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
        for(i=0;i<n-1;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }   
        dfs(1ll);
        cin>>m;
        while(m--){
            ll x,y;
            cin>>x>>y;
            if(x==y){
                cout<<0<<'\n';
            }
            else if(x==1||y==1){
                cout<<1<<'\n';
            }
            else{
                if((in[x]<in[y]&&out[x]>out[y])||(in[y]<in[x]&&out[y]>out[x])){
                    cout<<1<<'\n';
                }
                else{
                    cout<<2<<'\n';
                }
            }
        }
    }
}
