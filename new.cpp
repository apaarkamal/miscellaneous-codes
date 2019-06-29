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

const int N=10005,M=14;
int ptr=0,chain_no=0;

vector<P> gr[N],edges;
int subsize[N],dep[N],Par[N][M],dis[N];

int LCA(int u,int v){
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


void cal_sparse_matrix(int cur,int par){
    Par[cur][0]=par;
    for(int i=1;i<M;i++){
        Par[cur][i]=Par[Par[cur][i-1]][i-1];    
    }
    for(auto x:gr[cur]){
        if(par!=x.F){
            cal_sparse_matrix(x.F,cur);
        }            
    }
}

void dfs(int cur,int par){
    subsize[cur]=1;
    dep[cur]=dep[par]+1;
    for(auto x:gr[cur]){
        if(x.F!=par){
            dis[x.F]=dis[cur]+x.S;
            dfs(x.F,cur);
            subsize[cur]+=subsize[x.F];
        }
    }
}

void edge(){
    int x,y,w;
    cin>>x>>y>>w;
    gr[x].pb({y,w});
    gr[y].pb({x,w});
    edges.pb({x,y});
}

int kth_parent(int u,int k){
    k--;
    for(int i=M-1;i>=0;i--){
        if((k>>i)&1){
            u=Par[u][i];
        } 
    }
    return u; 
}

void clr(int n){
    edges.clear();
    for(int i=0;i<=n;i++){
        gr[i].clear();
        subsize[i]=0;   
        dis[i]=0;
        dep[i]=0;   
        for(int j=0;j<M;j++){
            Par[i][j]=0;           
        }
    }
    ptr=0;
}

int32_t main()
{
    the_martian();
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        for(i=1;i<n;i++){
            edge();                
        }
        ptr=0;
        chain_no=0;
        dfs(1,0);
        cal_sparse_matrix(1,0);

        while(1){
            string s;
            cin>>s;
            if(s=="DIST"){
                int u,v;
                cin>>u>>v;
                int lca=LCA(u,v);
                cout<<dis[u]+dis[v]-2*dis[lca]<<'\n';
            }
            else if(s=="KTH"){
                int u,v;
                cin>>u>>v>>k;
                int lca=LCA(u,v);
                if((dep[u]-dep[lca]+1)>=k){
                    cout<<kth_parent(u,k)<<'\n';
                }
                else{
                    cnt=k-(dep[u]-dep[lca]+1);
                    int dv=(dep[v]-dep[lca]);
                    dv=dv-cnt+1;
                    cout<<kth_parent(v,dv)<<'\n';
                }
            }
            else{
                break;
            }
        }
        clr(n);
    }
}