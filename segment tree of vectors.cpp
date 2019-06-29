#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

const int N=100005;

int a[N];

class segmenttreeofvectors
{
public:
    vector<int> st[N*4];
    void build(int l,int r,int node){
        if(l==r){
            st[node].pb(a[l]);
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,node*2+1);
        build(mid+1,r,node*2+2);
        merge(st[node*2+1].begin(), st[node*2+1].end(),st[node*2+2].begin(), st[node*2+2].end(),back_inserter(st[node]));
    }

    int query(int si,int se,int l,int r,int node,int k){
        if(se<l||si>r){
            return 0;
        }
        if(si>=l&&se<=r){
            return st[node].size()-(upper_bound(st[node].begin(), st[node].end(),k)-st[node].begin());
        }
        int mid=(si+se)/2;
        int q1=query(si,mid,l,r,node*2+1,k);
        int q2=query(mid+1,se,l,r,node*2+2,k);
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
        for(i=0;i<n;i++){
            cin>>a[i];
        }

    }
}