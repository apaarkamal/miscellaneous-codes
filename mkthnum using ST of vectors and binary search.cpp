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

vector<int> st[4*N];
int a[N],b[N];
map<int,int> mp;

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

int getans(int si,int se,int l,int r,int node,int k){
    if(se<l||si>r){
        return 0;
    }
    if(si>=l&&se<=r){
        return upper_bound(st[node].begin(), st[node].end(),k)-st[node].begin();
    }
    int mid=(si+se)/2;
    int q1=getans(si,mid,l,r,node*2+1,k);
    int q2=getans(mid+1,se,l,r,node*2+2,k);
    return q1+q2;
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
    // int t;cin>>t;while(t--)
    {
        int i,j,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(i=0;i<n;i++){
            a[i]=lower_bound(b,b+n,a[i])-b+1;
        }
        build(0,n-1,0);
        for(i=0;i<m;i++){
            int l,r,k;          
            cin>>l>>r>>k;
            l--;r--;
            int lo=1,hi=n;
            while(lo<hi){
                int mid=(lo+hi)/2;
                if(getans(0,n-1,l,r,0,mid)>=k){
                    hi=mid;
                }
                else{
                    lo=mid+1;
                }
            }
            cout<<b[lo-1]<<'\n';
        }
    }
}