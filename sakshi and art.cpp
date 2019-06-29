#include <bits/stdc++.h>

#define ff first

#define se second

#define pb push_back

#define nn 200100

#define mp make_pair

#define ll long long int

 // Consider this as a graph(lines as edges and points as nodes). We need to add edges, such that there is a Euler Path. Let be connected components of graph. Count the number of vertices(count of the open ends) with odd degree. If there is no vertex with odd degree, in a connected component, consider that there are two open ends, so add two to the count. You can leave atmost two open ends unpaired. That means, the number of pairings that need to be done are the minimum number of edges to be added.

using namespace std;

​

typedef pair<int,int> pii;

​

vector<int>adj[nn];

map<pii,int>a;

int n,v[nn];

​

int dfs(int node) //returning the number of odd degree vertices in connected component.

{

    if(v[node])

        return 0;

    v[node]=1;

    int ret=adj[node].size()%2;

    for(int u=0;u<adj[node].size();u++)

        ret+=dfs(adj[node][u]);

    return ret;

}

​

int main()

{

    ios_base::sync_with_stdio(0);

    int m;

    cin>>m;

    for(int i=0;i<m;i++)

    {

        int x1,y1,x2,y2;

        cin>>x1>>y1>>x2>>y2;

        if(a[mp(x1,y1)]==0)

            a[mp(x1,y1)]=++n; //assigning vertex to the point

        if(a[mp(x2,y2)]==0)

            a[mp(x2,y2)]=++n;

        int u=a[mp(x1,y1)],v=a[mp(x2,y2)];

        adj[u].pb(v);

        adj[v].pb(u);

    }

    int t=0,cnt=0;

    for(int i=1;i<=n;i++)

    {

        if(!v[i]) //not visited

        {

            cnt++;

            t+=max(dfs(i),2);

        }

    }

    int ans=max(cnt-1,(t-1)/2); 

    cout<<ans<<endl;

    return 0;

}