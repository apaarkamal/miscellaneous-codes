// https://codeforces.com/contest/1183/problem/H
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

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>k;
        string s;
        cin>>s;
        s+=s[n-1];
        for(i=n;i>0;i--){
            s[i]=s[i-1];               
        }
        int dp[n+1][n+1]={};
        vector<int> last(26,0);
        dp[0][0]=1;
        for(i=1;i<=n;i++){
            dp[i][0]=1;
            for(j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j-1];
                if(last[s[i]-'a']){
                    dp[i][j]-=dp[last[s[i]-'a']-1][j-1];
                }
                dp[i][j]+=dp[i-1][j];
            }        
            last[s[i]-'a']=i;
        }
        j=n;
        while(1&&j>=0){
            if(cnt+dp[n][j]<k){
                cnt+=dp[n][j];
                ans+=(n-j)*(dp[n][j]);
            }
            else{
                ans+=(k-cnt)*(n-j);
                cnt=k;
                break;
            }
            j--;
        }
        if(cnt==k){
            cout<<ans;
        }
        else{
            cout<<-1;
        }
    }
}