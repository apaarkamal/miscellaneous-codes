// https://www.spoj.com/problems/DQUERY/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> 
new_data_set; 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

const int N=1000005,M=33;

struct query{
    int l,r,id,block,ans;
};

bool comp(query q1,query q2){
    if(q1.block == q2.block) return q1.r < q2.r;
    return q1.block < q2.block;
}

int cnt[N];

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,sum=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>m;
        query q[m];
        int len=sqrt(n);
        for(i=0;i<m;i++){
            cin>>q[i].l>>q[i].r;
            q[i].l--;q[i].r--;
            q[i].block=q[i].l/len;q[i].id=i;
        }
        sort(q,q+m,comp);
        int l=0,r=0;
        for(i=0;i<m;i++){
            while(r<=q[i].r){
                cnt[a[r]]++;
                if(cnt[a[r]]==1){
                    ans++;
                }
                r++;  
            } 
            while(r>q[i].r+1){
                r--;
                cnt[a[r]]--;
                if(cnt[a[r]]==0){
                    ans--;
                }
            } 
            while(l<q[i].l){
                cnt[a[l]]--;
                if(cnt[a[l]]==0){
                    ans--;
                }
                l++;
            } 
            while(l>q[i].l){
            while(l>q[i].l){
                l--;
                cnt[a[l]]++;
                if(cnt[a[l]]==1){
                    ans++;
                }
            } 
            q[q[i].id].ans=ans;
        }
        for(i=0;i<m;i++){
            cout<<q[i].ans<<'\n';           
        }
    }
}