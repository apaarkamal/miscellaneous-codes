// https://www.codechef.com/LTIME73A/problems/QRYLAND
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

mt19937_64 rnd(228);

void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

const int N=500005,M=22;

int rn[N];
int Par[N][M],dep[N],timer=1,dis[N],tin[N],tout[N];
int val[N],flat[N],a[N],lenxor[N];
vector<int> gr[N];


class BIT
{
public:
    int a[N];
    // bit.add(i,a[i]);
    // sum=bit.sum(i);
    void add(int x, int val)
    {
        x++;
        while (x < N)
        {
            a[x] ^= val;
            x += (x&-x);
        }
    }
    int sum(int x)
    {
        int ret = 0;
        x++;
        while (x)
        {
            ret ^= a[x];
            x -= (x&-x);
        }
        return ret;
    }
}bit;

void pre(){
    for(int i=0;i<N;i++){
        rn[i]=rnd();       
        rn[i]=abs(rn[i]);
        if(i){
            lenxor[i]=lenxor[i-1]^rn[i];
        }
        // cout<<rn[i]<<'\n';
    }   
}

void cal_sparse_matrix(int cur,int par){
    Par[cur][0]=par;
    for(int i=1;i<M;i++){
        Par[cur][i]=Par[Par[cur][i-1]][i-1];    
    }
    for(auto x:gr[cur]){
        if(par!=x){
            cal_sparse_matrix(x,cur);
        }            
    }
}

int lca_using_depth(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    int diff=dep[u]-dep[v];
    for(int i=M-1;i>=0;i--){
        if(diff&(1<<i)){
            u=Par[u][i];
        }    
    }
    if(u==v) return v;
    for(int i=M-1;i>=0;i--){
        if(Par[u][i]!=Par[v][i]){
            u=Par[u][i];
            v=Par[v][i];
        }  
    }
    return Par[u][0];
}

void dfs(int cur,int par){
    tin[cur]=timer++;
    for(auto x:gr[cur]){
        if(x!=par){
            dep[x]=dep[cur]+1;
            dfs(x,cur);
        }
    }
    tout[cur]=timer++;
}

int32_t main()
{
    the_martian();
    pre();
    int t;cin>>t;while(t--)
    {
        memset(bit.a,0,sizeof(bit.a));
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        for(i=1;i<=n;i++){
            cin>>a[i];
            a[i]=rn[a[i]];
            gr[i].clear();
        }
        for(i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            gr[x].pb(y);                   
            gr[y].pb(x);                   
        }
        timer=1;
        dfs(1,0);
        cal_sparse_matrix(1,0);
        for(i=1;i<=n;i++){
            // cout<<tin[i]<<" "<<tout[i]<<'\n';
            bit.add(tin[i],a[i]);            
            bit.add(tout[i],a[i]);            
        }
        while(m--){
            int tp,x,y;
            cin>>tp>>x>>y;
            if(tp==1){
                int lca=lca_using_depth(x,y);
                int ds=dep[x]-dep[lca]+dep[y]-dep[lca]+1;
                if((bit.sum(tin[x])^bit.sum(tin[y])^a[lca])==lenxor[ds]){
                    cout<<"Yes\n";
                }
                else{
                    cout<<"No\n";
                }
            }
            else{
                bit.add(tin[x],a[x]);
                bit.add(tout[x],a[x]);
                a[x]=rn[y];
                bit.add(tin[x],a[x]);
                bit.add(tout[x],a[x]);
            }
        }
    }
}