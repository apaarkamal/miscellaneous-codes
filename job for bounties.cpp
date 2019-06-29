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
        string s;cin>>s;
        n=s.size();
        stack<pair<ll,ll>> S;
        S.push({(s[0]=='('?0:1),0});
        ll dp[n+1]={};
        for(i=1;i<n;i++){
            if(s[i]==')'){
                cnt=0;
                if(!S.empty()){
                    if(S.top().F==0){
                        dp[S.top().S]=2;
                        dp[i]=2;
                        S.pop();
                    }
                    else{
                        S.push({1,i});
                    }
                }
                else{
                    S.push({1,i});
                }
            }
            else{
                S.push({0,i});
            }
        }
        for(i=0;i<n;i++){
            if(dp[i]==2){
                cnt++;
            }
            else{
                cnt=0;
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
}