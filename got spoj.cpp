// https://www.spoj.com/problems/GOT/
// https://raw.githubusercontent.com/tr0j4n034/SPOJ/master/GOT.cpp
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back


#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

const int N=100005,M=22;
int ptr=0,chain_no=0;

vector<P> gr[N],edges;
int subsize[N],dep[N],Par[N][M],a[N],b[N],c[N];
int chain_head[N],chain_Ind[N],chain_size[N];
int Base_array[N],pos_in_Base[N];

class segmenttreeofvectors
{
public:
    vector<int> st[N*4];
    void build(int l,int r,int node){
        if(l==r){
            st[node].pb(Base_array[l]);
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,node*2+1);
        build(mid+1,r,node*2+2);
        merge(st[node*2+1].begin(), st[node*2+1].end(),st[node*2+2].begin(), st[node*2+2].end(),back_inserter(st[node]));
    }

    bool query(int si,int se,int l,int r,int node,int k){
        if(se<l||si>r){
            return false;
        }
        if(si>=l&&se<=r){
            auto it=lower_bound(st[node].begin(), st[node].end(),k);
            if(it!=st[node].end()&&*it==k){
                return true;
            }
            else{
                return false;
            }
        }
        int mid=(si+se)/2;
        bool q1=query(si,mid,l,r,node*2+1,k);
        bool q2=query(mid+1,se,l,r,node*2+2,k);
        return (q1||q2);
    }
}tr;

void HLD(int cur,int par){
    if(chain_head[chain_no]==0){
        chain_head[chain_no]=cur;
    }
    chain_Ind[cur]=chain_no;
    pos_in_Base[cur]=ptr;
    Base_array[ptr++]=a[cur];
    chain_size[chain_no]++;

    int sp_chld=-1,w_sp_chld;
    for(auto x:gr[cur]){
        if(x.F!=par&&(sp_chld==-1||subsize[x.F]>subsize[sp_chld])){
            sp_chld=x.F;
            w_sp_chld=x.S;
        }     
    }
    if(sp_chld!=-1){
        HLD(sp_chld,cur);
    }
    for(auto x:gr[cur]){
        if(x.F!=par&&x.F!=sp_chld){
            chain_no++;
            HLD(x.F,cur);
        }     
    }
}

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
            dfs(x.F,cur);
            subsize[cur]+=subsize[x.F];
        }
    }
}

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}

void edge(){
    int x,y,w=1;
    x=uget();
    y=uget();
    gr[x].pb({y,w});
    gr[y].pb({x,w});
    edges.pb({x,y});
}

bool query_up(int u,int v,int k){
    if(v==u){
        if(a[u]==k) return true;
        return false;
    }
    int uchain=chain_Ind[u],vchain=chain_Ind[v],ans=0;
    while(1){
        uchain=chain_Ind[u];
        if(uchain==vchain){
            if(v==u){
                if(a[u]==k) return true;
                return false;
            }
            if(tr.query(0,ptr-1,pos_in_Base[v],pos_in_Base[u],0,k)){
                return true;
            }
            break;
        }
        else{
            if(tr.query(0,ptr-1,pos_in_Base[chain_head[uchain]],pos_in_Base[u],0,k)){
                return true;
            }
            u=Par[chain_head[uchain]][0];
        }
    }   
    return false;
}

void clr(int n){
    edges.clear();
    for(int i=0;i<=n;i++){
        gr[i].clear();
        subsize[i]=0;   
        dep[i]=0;   
        chain_head[i]=0;   
        chain_Ind[i]=0;   
        chain_size[i]=0;   
        Base_array[i]=0;   
        pos_in_Base[i]=0;   
        for(int j=0;j<M;j++){
            Par[i][j]=0;           
        }
    }
    for(int i=0;i<=N*4;i++){
        tr.st[i].clear();            
    }
    ptr=0;
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    int n,m;
    while(scanf("%lld%lld", &n, &m)!=EOF)
    {
        int i,j,k,ans=0,cnt=0,sum=0;
        for(i=1;i<=n;i++){
            a[i]=uget();                
        }
        for(i=1;i<n;i++){
            edge(); 
        }
        ptr=0;
        chain_no=0;
        dfs(1,0);
        cal_sparse_matrix(1,0);
        HLD(1,0);
        tr.build(0,ptr-1,0);
        while(m--){
            int u,v;
            u=uget();
            v=uget();
            k=uget();
            int lca=LCA(u,v);
            if(query_up(u,lca,k)||query_up(v,lca,k)){
                cout<<"FIND\n";
            }
            else{
                cout<<"NOTFIND\n";
            }
        }
        clr(n);
    }
}