// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/sherlock-and-highways/description/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N=100005;

vector<pair<int,int>> gr[N],brdgs;
int tin[N],tout[N],low[N],vis[N],tme,chld[N],comp[N],dis[N];
vector<int> art_p,grb[N];
 
void dfs(int cur,int par){ 
    vis[cur]=low[cur]=tme++;
    for(auto &x:gr[cur]){
        if(!vis[x.F]){
            dfs(x.F,cur);
            chld[cur]++;
            low[cur]=min(low[cur],low[x.F]);
            if(par && low[x.F] >= vis[cur]){
                art_p.pb(cur);
            }
            if(low[x.F] > vis[cur]){
                x.S=1;// bridge edge
            }   
        }   
        else if(x.F!=par){
            low[cur]=min(low[cur],vis[x.F]);
        }  
    }
    if(par==0 && chld[cur]>1) art_p.pb(cur); // for root
}

void dfs1(int cur,int cnt){
    vis[cur]=1;
    comp[cur]=cnt;
    for(auto x:gr[cur]){
        if(!vis[x.F] && x.S==0){
            dfs1(x.F,cnt);
        }
    }
}

void bfs(int src){
    queue<int> Q;
    Q.push(src);
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        vis[cur]=1;
        for(auto x:grb[cur]){
            if(!vis[x]){
                dis[x]=dis[cur]+1;
                Q.push(x);
            }
        }
    }
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        for(i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            gr[x].pb({y,0});           
            gr[y].pb({x,0});           
        }
        for(i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,0);
            } 
        }
        sort(brdgs.begin(), brdgs.end());
        for(i=1;i<=n;i++){
            sort(gr[i].begin(), gr[i].end());
        }
        for(i=1;i<=n;i++){
            for(auto x:gr[i]){
                if(x.S){// reverse edge will also be a bridge edge
                    P p={i,0};
                    auto it=lower_bound(gr[x.F].begin(), gr[x.F].end(),p);
                    it->S=1;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        cnt=1;
        for(i=1;i<=n;i++){
            if(!vis[i]){// filling same components 
                dfs1(i,cnt);  
                cnt++;
            }
        }
        for(i=1;i<=n;i++){
            for(auto x:gr[i]){
                if(x.S){// making bridge tree
                    grb[comp[i]].pb(comp[x.F]);
                }
            }
        }
        // diameter
        bfs(1);
        int lf=0;
        for(i=1;i<cnt;i++){
            if(dis[lf]<dis[i]){
                lf=i;
            }         
        }
        bfs(lf);
        lf=0;
        for(i=1;i<cnt;i++){
            if(dis[lf]<dis[i]){
                lf=i;
            }         
        }
        cout<<cnt-2<<" "<<dis[lf];
    }
}