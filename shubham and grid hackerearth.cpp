// https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/shubham-and-grid-806c2c66/description/
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

const int N=25;

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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int a[N][N],num[N][N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=1,sum=0;
        cin>>n>>m;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                char ch;
                cin>>ch;
                a[i][j]=ch-'a';                   
                num[i][j]=cnt++;
            }            
        }
        G.init(cnt,0,cnt);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                for(int k=0;k<4;k++){
                    int xx=i+dx[k];        
                    int yy=j+dy[k];
                    if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&a[xx][yy]==a[i][j]+1){
                        G.add_edge(num[i][j],num[xx][yy],1);
                    }        
                }
                if(a[i][j]==0){
                    G.add_edge(0,num[i][j],1);
                }
                if(a[i][j]==3){
                    G.add_edge(num[i][j],cnt,1);
                }
            }            
        }
        G.Dinic();
        cout<<G.flow;
    }
}