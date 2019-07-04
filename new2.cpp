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

const int N=100005,M=33;

new_data_set S;

int32_t main()
{
    the_martian();
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m;
        while(m--){
            int type;
            cin>>type;
            if(type==1){
                int x;
                cin>>x;
                x+=ans;
                S.insert(x);
            }
            else{
                int l,r;
                cin>>l>>r;
                l+=ans;r+=ans;
                int idxr=S.order_of_key(r);
                if(*S.find_by_order(idxr)!=r){
                    cnt=r;
                }
                else{
                    while(l<r){
                        cout<<l<<" "<<r<<'\n';
                        int mid=(l+r)/2;
                        int idxm=S.order_of_key(mid);
                        if(*S.find_by_order(idxm)==mid){
                            if(idxr-idxm==r-mid){
                                r=mid;
                            }
                            else{
                                l=mid+1;
                                cnt=max(ans,mid+1);
                            }
                        }
                        else{
                            cnt=max(cnt,mid);
                            int val=*S.find_by_order(idxm);
                            cout<<"val "<<val<<'\n';
                            if(r-val==idxr-idxm){
                                l=mid;
                            }
                            else{
                                r=val;
                            }
                        }
                    }
                }
                ans+=cnt;
                ans%=n;
                cout<<cnt<<"f "<<ans<<'\n';
            }
        }
        S.clear();
    }
}