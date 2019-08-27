#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N=100005;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        map<int,int> mp;
        vector<int> ansv;
        for(i=n-1;i>=0;i--){
            if(mp[a[i]]==0){
                ansv.pb(a[i]);
                mp[a[i]]++;
            }              
        }       
        reverse(ansv.begin(), ansv.end());
        for(auto x:ansv){
            cout<<x<<'\n';       
        }
    }
}