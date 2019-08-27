// https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/decaying-roadsnov-easy-8e930584/description/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005;

const int NN=500005,MM=500005;
int ec=0;
struct MaxFlow{
    vector<int> gr[NN];
    struct Edge{
        int x,y,w;
    }edges[MM],temp[MM];
    int source,sink,flow,n,Level[NN],Q[NN],PV[NN];
    void init(int sz,int SRC,int SN){
        n=sz,source=SRC,sink=SN,flow=ec=0;
        for(int i=0;i<=n;i++) gr[i].clear();            
    }
    void add_edge(int x,int y,int w){
        gr[x].pb(ec);
        edges[ec++]={x,y,w};
        gr[y].pb(ec);
        edges[ec++]={y,x,0};// for undirected replace 0 with w
    }
    int BlockFlow(int cur,int cnt){//dfs
        if(cur==sink) return cnt;
        for(int &i=PV[cur];i>=0;i--){
            int cur_e=gr[cur][i];
            if(edges[cur_e].w && Level[edges[cur_e].y] == Level[cur]+1){
                if(int val = BlockFlow(edges[cur_e].y,min(cnt,edges[cur_e].w))){
                    edges[cur_e].w -= val;
                    edges[cur_e ^ 1].w += val;
                    return val;
                }
            }
        }
        return 0;
    }
    bool GetLevel() {// bfs
        int head = 0, tail = 0, i;
        for (i = 0; i <= n; i++)Level[i] = -1;
        Q[++tail] = source; Level[source] = 0;
        while (head < tail) {
            int cur = Q[++head];
            for (auto &t : gr[cur]) {
                if (edges[t].w && Level[edges[t].y] == -1) {
                    Level[edges[t].y] = Level[cur] + 1;
                    Q[++tail] = edges[t].y;
                }
            }
        }
        return Level[sink] != -1;
    }
    void Dinic() {
        int i, t;
        flow = 0;
        while (GetLevel()) {
            for (i=0;i<=n;i++) PV[i]=gr[i].size()-1;
            while (t = BlockFlow(source, 1e18)) {
                flow += t;
            }
        }
    }
}G;
// dont forget to initialise

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,cnt=0,sum=0;
        cin>>n>>m>>k;
        vector<P> v(k);
        G.init(m+n+2,0,m+n+1);
        for(i=0;i<n;i++){
            G.add_edge(0,i+1,1);                   
        }
        for(i=0;i<k;i++){
            cin>>v[i].F>>v[i].S;       
            G.add_edge(v[i].F,v[i].S+n,1);           
        }
        int cap[m],pos[m];
        for(i=0;i<m;i++){
            cin>>cap[i];                   
        }
        int z;
        cin>>z;
        vector<P> q(z);
        int ans[z];
        for(i=0;i<z;i++){
            int r,p;
            cin>>r>>p;
            r--;
            q[i].F=r;q[i].S=p;
            cap[r]-=p;
        }
        for(i=0;i<m;i++){
            pos[i]=ec;
            G.add_edge(i+n+1,m+n+1,cap[i]);
        }
        G.Dinic();
        cnt=G.flow;
        for(i=z-1;i>=0;i--){
            int r,p;
            r=q[i].F;p=q[i].S;
            G.edges[pos[r]].w+=p;
            G.Dinic();
            cnt+=G.flow;
            ans[i]=cnt;
        }
        for(i=0;i<z;i++){
            cout<<ans[i]<<'\n';                   
        }
    }
}