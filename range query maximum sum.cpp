#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, 
tree_order_statistics_node_update> 
new_data_set; 

const ll N=100005;
ll a[N];

struct ST{
    ll prefixsum=INT_MIN,suffixsum=INT_MIN,sum=INT_MIN,maxsum=INT_MIN;
}st[4*N];

void build(ll l,ll r,ll node){
    if(l==r){
        st[node].prefixsum=a[l];
        st[node].suffixsum=a[l];
        st[node].sum=a[l];
        st[node].maxsum=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(l,mid,node*2+1);
    build(mid+1,r,node*2+2);
    st[node].sum=st[node*2+2].sum+st[node*2+1].sum;
    st[node].prefixsum=max(st[node*2+1].prefixsum,st[node*2+1].sum+st[node*2+2].prefixsum);
    st[node].suffixsum=max(st[node*2+2].suffixsum,st[node*2+2].sum+st[node*2+1].suffixsum);
    st[node].maxsum=max({st[node].prefixsum,st[node].suffixsum
                    ,st[node*2+1].maxsum,st[node*2+2].maxsum,
                    st[node*2+1].suffixsum+st[node*2+2].prefixsum});
}

ST getans(ll si,ll se,ll l,ll r,ll node){
    // cout<<si<<" "<<se<<'\n';
    ST result;
    result.sum = result.prefixsum =  result.suffixsum =  result.maxsum = INT_MIN;
    if(se<l||si>r){
        return result;
    }
    if(si>=l&&se<=r){
        return st[node];
    }
    ll mid=(si+se)/2;
    if(l>mid){
        return getans(mid+1,se,l,r,node*2+2);
    }
    else if(r<=mid){
        return getans(si,mid,l,r,node*2+1);
    }
    ST q1=getans(si,mid,l,r,node*2+1);
    ST q2=getans(mid+1,se,l,r,node*2+2);
    result.sum=q1.sum+q2.sum;
    result.prefixsum=max(q1.prefixsum,q1.sum+q2.prefixsum);
    result.suffixsum=max(q2.suffixsum,q2.sum+q1.suffixsum);
    result.maxsum=max({result.prefixsum,result.suffixsum,q1.maxsum,q2.maxsum
                        ,q1.suffixsum+q2.prefixsum});
    return result;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;  
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
        }  
        build(0,n-1,0);
        cin>>m;
        while(m--){
            ll l,r;cin>>l>>r;
            l--;r--;
            cout<<getans(0,n-1,l,r,0).maxsum<<'\n';
        }
    }
}