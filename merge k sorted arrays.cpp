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
        cin>>n>>m;
        int a[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }        
        }
        int poin[n]={};
        vector<int> v;
        while(1){
            int mn=INT_MAX,pos=-1;
            for(i=0;i<n;i++){
                if( poin[i] < m && a[i][poin[i]] < mn){
                    mn=a[i][poin[i]];
                    pos=i;
                }            
            }
            if(pos==-1){
                break;
            }
            v.pb(a[pos][poin[pos]]);
            poin[pos]++;
        }
        for(auto x:v){
            cout<<x<<" ";          
        }
    }
}