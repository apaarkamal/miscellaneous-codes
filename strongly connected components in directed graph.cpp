#include<bits/stdc++.h> 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m,a,b,cost[200000];
vector<long> g[200000],gr[200000];
long long ans;
long used[200000];
vector<long> temp,order,comp;

void dfs1(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dfs1(q);
 }
 order.push_back(v);
}

void dfs2(long v)
{
 used[v]=1;
 for (int i=0;i<gr[v].size();i++)
 {
  long q=gr[v][i];
  if (used[q])continue;
  dfs2(q);
 }
 comp.push_back(v);
}

int main(){
ios_base::sync_with_stdio(0);
//cin.tie(0);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
cin>>n;
for (int i=1;i<=n;i++)
 cin>>cost[i];
cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 gr[b].push_back(a);
}

ans=1;
for (int i=1;i<=n;i++)
 if (used[i]==0)dfs1(i);
 
for (int i=1;i<=n;i++) 
  used[i]=0;

long long tans=0;
for (int i=1;i<=n;i++)
{
 long v=order[n-i];
 if (used[v])continue;
 dfs2(v);
 temp.clear();
 for (int j=0;j<comp.size();j++)
  temp.push_back(cost[comp[j]]);
 comp.clear();
}
cout<<tans<<" "<<ans<<endl;

cin.get();cin.get();
return 0;}