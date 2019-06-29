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

vector<P> v[N];
V<int> eu;
int fs[N],st[N*4*2],dep[N];

void dfs1(int cur,int par,int d){
    eu.pb(cur);
    dep[cur]=d;
    fs[cur]=eu.size()-1;
    for(auto x:v[cur]){
        if(x.F!=par){
            dfs1(x.F,cur,d+1);
            eu.pb(cur);
        }
    }
}

void build(int l,int r,int node){
    if(l==r){
        st[node]=l;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,node*2+1);
    build(mid+1,r,node*2+2);
    if (dep[eu[st[2*node+1]]] < dep[eu[st[2*node+2]]]){
        st[node] = st[2*node+1];
    } 
    else{
        st[node] = st[2*node+2]; 
    }
}

int getans(int si,int se,int l,int r,int node){
    if(se<l||si>r){
        return -1;
    }
    if(si>=l&&se<=r){
        return st[node];
    }
    int mid=(si+se)/2;
    int q1=getans(si,mid,l,r,node*2+1);
    int q2=getans(mid+1,se,l,r,node*2+2);
    if(q1==-1) return q2;
    else if(q2==-1) return q1;
    return (dep[q1]<dep[q2])?q1:q2;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        for(i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            v[x].pb({y,w});
            v[y].pb({x,w});
        }
        dfs1(1,0,1);
        // for(auto x:eu){
        //     cout<<x<<" "<<fs[x]<<" "<<dep[x]<<'\n';
        // }cout<<'\n';
        n=eu.size();
        build(0,n-1,0);
        cin>>m;
        while(m--){
            int x,y;
            cin>>x>>y;
            if(fs[x]>fs[y]){
                swap(x,y);
            }
            ans=getans(0,n-1,fs[x],fs[y],0);
            db(fs[x],fs[y],ans,eu[ans]);
        }
        for(i=0;i<=n;i++){
            v[i].clear();           
        }
        eu.clear();
    }
}