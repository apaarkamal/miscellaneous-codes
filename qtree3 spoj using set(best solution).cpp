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

const int N=100005,M=18;
int ptr=0,chain_no=0,ans=-1;

vector<P> gr[N],edges;
int subsize[N],dep[N],Par[N][M];
int chain_head[N],chain_Ind[N],chain_size[N],node_in_base_array[N],is_chain_head[N];
int Base_array[N],pos_in_Base[N];
vector<int> all_chains_roottox[N];

set<int> S[M];

void HLD(int cur,int par,int weight){
    if(chain_head[chain_no]==0){
        chain_head[chain_no]=cur;
        is_chain_head[cur]=chain_no;
    }
    chain_Ind[cur]=chain_no;
    pos_in_Base[cur]=ptr;
    node_in_base_array[ptr]=cur;
    Base_array[ptr++]=weight;//0
    chain_size[chain_no]++;

    int sp_chld=-1,w_sp_chld;
    for(auto x:gr[cur]){
        if(x.F!=par&&(sp_chld==-1||subsize[x.F]>subsize[sp_chld])){
            sp_chld=x.F;
            w_sp_chld=x.S;
        }     
    }
    if(sp_chld!=-1){
        HLD(sp_chld,cur,w_sp_chld);
    }
    for(auto x:gr[cur]){
        if(x.F!=par&&x.F!=sp_chld){
            chain_no++;
            HLD(x.F,cur,x.S);
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

void dfs2(int cur,int par){
    for(auto x:all_chains_roottox[par]){
        all_chains_roottox[cur].pb(x);
    }
    if(is_chain_head[cur]!=-1){
        all_chains_roottox[cur].pb(is_chain_head[cur]);
    }
    for(auto x:gr[cur]){
        if(x.F!=par){
            dfs2(x.F,cur);
        }
    }
}

void edge(){
    int x,y,w=0;
    scanf("%lld%lld",&x,&y);
    gr[x].pb({y,w});
    gr[y].pb({x,w});
    edges.pb({x,y});
}

void update(int u){
    if(Base_array[pos_in_Base[u]]==1){
        Base_array[pos_in_Base[u]]=0;
        S[chain_Ind[u]].erase(pos_in_Base[u]);
    }
    else{
        Base_array[pos_in_Base[u]]=1;
        S[chain_Ind[u]].insert(pos_in_Base[u]);
    }
}

int query_up(int u,int v){
    int ans=-1;
    while(1){
        int uchain=chain_Ind[u],vchain=chain_Ind[v];
        if(uchain==vchain){
            if(S[uchain].empty()) break;
            int cur=*S[uchain].begin();
            if(cur<=pos_in_Base[u]){
                ans=node_in_base_array[cur];   
            }
            break;
        }
        else{
            if(S[uchain].empty()){
                u=Par[chain_head[uchain]][0];
            }
            else{
                int cur=*S[uchain].begin();
                if(cur<=pos_in_Base[u]){
                    ans=node_in_base_array[cur];
                }
                u=Par[chain_head[uchain]][0];
            }
        }
    }
    return ans;
}

int32_t main()
{
    // the_martian();
    int n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        int i,j,k,cnt=0,sum=0;
        for(i=1;i<n;i++){
            edge();                
        }
        ptr=0;
        chain_no=0;
        dfs(1,0);
        memset(is_chain_head,-1,sizeof(is_chain_head));
        HLD(1,0,0);

        //store all chains from 1 to x
        dfs2(1,0);
        //queries
        while(m--){
            int t,u;
            scanf("%lld%lld",&t,&u);
            if(t){
                printf("%lld\n",query_up(u,1));
            }
            else{
                int pos=pos_in_Base[u];
                update(u);
            }
        }
    }
}