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


const int N=100005;

V<int> v[N];
int in[N],out[N],p[N],a[N],tme=1,vis[N];

void dfs(int cur){
    in[cur]=tme;
    for(auto x:v[cur]){
        tme++;
        dfs(x);
    }
    out[cur]=tme;
}

class segmenttreewithlazy
{
public:
    int st[N*4],lazy[N*4];
    void build(int start,int end,int node){
        if(start==end){
            st[node]=1;
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,node*2+1);
        build(mid+1,end,node*2+2);
        st[node]=(st[2*node+1]+st[2*node+2]);
    }

    void update_range(int start,int end,int l,int r,int val,int node){
        if(lazy[node]!=-1){
            //update lazy node and forward value to children
            st[node]=(end-start+1)*lazy[node];
            if(start!=end){
                lazy[2*node+1]=lazy[node];
                lazy[2*node+2]=lazy[node];
            }
            lazy[node]=-1;
        }
        if(start>end||end<l||start>r){//no overlap
            return ;
        }
        if(start>=l&&end<=r){//complete overlap
            //update lazy node and forward value to children
            st[node]=(end-start+1)*val;
            if(start!=end){
                lazy[2*node+1]=val;
                lazy[2*node+2]=val;
            }
            return ;
        }
        int mid=(start+end)/2;
        update_range(start,mid,l,r,val,node*2+1);
        update_range(mid+1,end,l,r,val,node*2+2);
        st[node]=st[2*node+1]+st[2*node+2];
    }

    int query(int start,int end,int l,int r,int node){
        if(start>end||end<l||start>r){
            return 0;
        }
        if(lazy[node]!=-1){
            //update lazy node and forward value to children
            st[node]=(end-start+1)*lazy[node];
            if(start!=end){
                lazy[2*node+1]=lazy[node];
                lazy[2*node+2]=lazy[node];
            }
            lazy[node]=-1;
        }
        if(start>=l&&end<=r){
            return st[node];
        }
        int mid=(start+end)/2;
        int q1=query(start,mid,l,r,node*2+1);
        int q2=query(mid+1,end,l,r,node*2+2);
        return q1+q2;
    }
}tree;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>p[i];
            v[p[i]].pb(i);
        }
        for(i=1;i<=n;i++){
            if(p[i]==0){
                dfs(i);
                break;
            }                   
        }
        tree.build(1,n,0);
        for(i=0;i<4*N;i++){
            tree.lazy[i]=-1;         
        }
        cin>>m;
        while(m--){
            int x,s;
            cin>>x>>s;
            i=s;
            if(x==1){
                int l=in[i]+1,r=out[i];
                tree.update_range(1,n,l,r,1,0);
            }
            else if(x==2){
                int l=in[i]+1,r=out[i];
                tree.update_range(1,n,l,r,0,0);
            }
            else{
                int l=in[i]+1,r=out[i];
                cout<<tree.query(1,n,l,r,0)<<'\n';
            }
        }
    }
}