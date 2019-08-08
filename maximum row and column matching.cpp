// https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/easy-game/description/
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005;

const int NN=5005,MM=500005;
struct MaxFlow{
    vector<int> gr[NN];
    struct Edge{
        int x,y,w;
    }edges[MM];
    int source,sink,flow,n,ec,Level[NN],Q[NN],PV[NN];
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
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        string s[n];
        for(i=0;i<n;i++){
            cin>>s[i];                   
        }
        G.init(n+m+2,0,n+m+1);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(s[i][j]=='W'){
                    G.add_edge(i+1,j+n+1,1);
                }                                  
            }                   
        }
        for(i=0;i<n;i++){
            G.add_edge(0,i+1,1);                   
        }
        for(i=0;i<m;i++){
            G.add_edge(i+n+1,n+m+1,1);                   
        }
        G.Dinic();
        cout<<G.flow<<'\n';
    }
}