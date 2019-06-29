#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 1e5 + 5;
vector<pair<ll,long long> > Tree[N];
ll par[N];

ll p[N][41]; // p[i][j] stores i's 2ˆj th parent
ll level[N];
long long distFromRoot[N];

//helper dfs to fill out immaediate parent and level of vertices
void dfs_pre(ll u,ll pa,ll cl) {
   p[u][0] = pa;
   level[u] = cl;
   for(ll i = 0;i < Tree[u].size();i++) {
      if(Tree[u][i].first != pa) {
        distFromRoot[Tree[u][i].first] = distFromRoot[u] + Tree[u][i].second;
        dfs_pre(Tree[u][i].first,u,cl + 1);
      }
   }
}

//helper dfs called and array p filled
void preprocess(ll n) {
   dfs_pre(1,0,1);
   for(ll i = 0;i <= n;i++) {
      for(ll j = 1;j <= 40;j++) p[i][j] = 0;
   }
   for(ll j = 1;j <= 40;j++) {
      for(ll i = 1;i <= n;i++) {
         p[i][j] = p[p[i][j - 1]][j - 1];
      }
   }
}

//Calculates lowest common ancestor of u and v
ll lca(ll u,ll v) {
   if(level[u] < level[v]) swap(u,v); // Have u at a lower level
   ll log = 0;
   while(  (1<<log) < (level[u] - level[v]) ) log++;
   for(ll i = log;i >= 0;i--) {
      if(level[u] - (1<<i) >= level[v] ) u = p[u][i]; //bringing u to v's level
   }
   if(u == v) return u;
   log = 0;
   //finding lca
   while((1<<log) <= level[u] ) log++;
   for(ll i = log;i >= 0;i--) {
      if(p[u][i] != 0 && p[u][i] != p[v][i]) {
         u = p[u][i];
         v = p[v][i];
      }
   }
   return p[u][0];
}

long long dist(ll u,ll v) {
  return distFromRoot[u] + distFromRoot[v] - 2 * distFromRoot[lca(u,v)];
}

/* 
  Centroid Decomposition 
  'Tree' is decomposed and the parents in the centroid tree are set in 'par'.
  */ 

ll ss[N];
vector<ll> TreeCopy[N];
vector<long long> dl[N];
vector<long long> dlParent[N];

ll nn;

void findSubtreeSizes(ll u,ll p,vector<ll> &vv) {
  vv.push_back(u);
  ss[u] = 1;
  nn++;
  for(auto v : TreeCopy[u]) {
    if(v != p) {
      findSubtreeSizes(v,u,vv);
      ss[u] += ss[v];
    }
  }
}

ll findCentroid(ll u,ll p) {
  for(auto v : TreeCopy[u]) {
    if(v != p && ss[v] > nn/2)
      return findCentroid(v,u);
  }
  return u;
}

void decompose(ll u,ll p) {
  nn = 0;
  vector<ll> v;
  findSubtreeSizes(u,0,v);
  ll centroid = findCentroid(u,0);
  dl[centroid].clear();
  dlParent[centroid].clear();
  for(ll i = 0;i < nn;i++) {
    dl[centroid].push_back(dist(centroid,v[i]));
    dlParent[centroid].push_back(dist(p,v[i]));
  }
  sort(dl[centroid].begin(), dl[centroid].end());
  sort(dlParent[centroid].begin(), dlParent[centroid].end());
  par[centroid] = p;
  for(auto v : TreeCopy[centroid]) {
    for(ll i = 0;i < TreeCopy[v].size();i++) {
      if(TreeCopy[v][i] == centroid) {
        TreeCopy[v].erase(TreeCopy[v].begin()+i);
        break;
      }
    }
    decompose(v,centroid);
  }
}

void centroidDecomposition(ll n) {
  for(ll i = 1;i <= n;i++) {
    TreeCopy[i].clear();
    for(ll j = 0;j < Tree[i].size();j++) 
      TreeCopy[i].push_back(Tree[i][j].first);
  }
  decompose(1,0);
}

/* End - Centroid Decomposition */

ll query(ll u,long long l) {
  return ll(upper_bound(dl[u].begin(), dl[u].end(),l) - dl[u].begin());
}

ll queryp(ll u,long long l) {
  return ll(upper_bound(dlParent[u].begin(), dlParent[u].end(),l) - dlParent[u].begin());
}

ll check(ll l, ll u){
    ll cc = u;
    ll ans = query(u,l);
    while(par[cc]) {
      ans += query(par[cc],l - dist(u,par[cc])) - queryp(cc,l - dist(u,par[cc]));
      cc = par[cc];
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll n; cin>>n;
        ll k[n+1]={};
        for(ll i = 1; i <= n; i++){
            cin>>k[i];
        }
        for(ll i = 1;i < n;i++) {
        ll a,b;
        cin>>a>>b;
        Tree[a].push_back({b,1});
        Tree[b].push_back({a,1});
        }
        preprocess(n);
        centroidDecomposition(n);
        for(ll i=1;i<=n;i++){
            ll lf=0,rt=n;
            while(lf<rt){
                ll mid=(lf+rt)/2;
                if(n-check(mid,i)<k[i]){
                    rt=mid-1;
                }
                else{
                    lf=mid+1;
                }
            }
            cout<<lf-1<<" ";
        }

}