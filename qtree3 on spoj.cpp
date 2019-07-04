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
int ptr=0,chain_no=0,ans=-1;

vector<P> gr[N],edges;
int subsize[N],dep[N],Par[N][M];
int chain_head[N],chain_Ind[N],chain_size[N],at_that_in_node[N];
int Base_array[N],pos_in_Base[N];

class segmenttree
{
public:
    int st[N*4];
    void build(int l,int r,int node){
        if(l==r){
            st[node]=Base_array[l];
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,node*2+1);
        build(mid+1,r,node*2+2);
        st[node]=(st[2*node+1]+st[2*node+2]);
    }

    void update(int l,int r,int indup,int val,int node){
        if(l==r){
            Base_array[l]=val;
            st[node]=val;
            return;
        }
        else{
            int mid=(l+r)/2;
            if(indup>=l&&indup<=mid){
                update(l,mid,indup,val,node*2+1);
            }
            else{
                update(mid+1,r,indup,val,node*2+2);
            }
            st[node]=(st[2*node+1]+st[2*node+2]);  
        }
    }

    int query(int si,int se,int l,int r,int node){
        if(se<l||si>r||l>r){
            return 0;
        }
        if(si>=l&&se<=r){
            return st[node];
        }
        int mid=(si+se)/2;
        int q1=query(si,mid,l,r,node*2+1);
        int q2=query(mid+1,se,l,r,node*2+2);
        return q1+q2;
    }

    void go(int l,int r){
        if(l==r){
            if(Base_array[l]==1){
                ans=at_that_in_node[l];
            }
            return ;
        }
        int mid=(l+r)/2;
        int sum1=query(0,ptr-1,l,mid,0);
        int sum2=query(0,ptr-1,mid+1,r,0);
        if(sum1==0&&sum2==0){
            return;
        }
        else if(sum1){
            go(l,mid);
        }
        else{
            go(mid+1,r);
        }
        return ;
    }
}tr;

void HLD(int cur,int par,int weight){
    if(chain_head[chain_no]==0){
        chain_head[chain_no]=cur;
    }
    chain_Ind[cur]=chain_no;
    pos_in_Base[cur]=ptr;
    at_that_in_node[ptr]=cur;
    Base_array[ptr++]=weight;
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

void edge(){
    int x,y,w=0;
    cin>>x>>y;
    gr[x].pb({y,w});
    gr[y].pb({x,w});
    edges.pb({x,y});
}

void query_up(int u,int v){
    ans=-1;
    int uchain=chain_Ind[u],vchain=chain_Ind[v];
    while(1){
        uchain=chain_Ind[u];
        if(uchain==vchain){
            tr.go(pos_in_Base[v],pos_in_Base[u]);
            break;
        }
        else{
            tr.go(pos_in_Base[chain_head[uchain]],pos_in_Base[u]);
            u=Par[chain_head[uchain]][0];
        }
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,cnt=0,sum=0;
        cin>>n>>m;
        for(i=1;i<n;i++){
            edge();                
        }
        ptr=0;
        chain_no=0;
        dfs(1,0);
        HLD(1,0,0);
        tr.build(0,ptr-1,0);

        while(m--){
            int t,u;
            cin>>t>>u;
            if(t){
                query_up(u,1);
                cout<<ans<<'\n';
            }
            else{
                int pos=pos_in_Base[u];
                tr.update(0,ptr-1,pos,1-Base_array[pos],0);
            }
        }
    }
}