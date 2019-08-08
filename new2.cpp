#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(x) cout <<#x<<": "<<x<<'\n';

const int N=2000005;

vector<int> v[N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        int a[n+1],pre[n+1];
        a[0]=pre[0]=0;
        for(i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=a[i];
        }
        for(i=1;i<=n;i++){
            pre[i]^=pre[i-1];
        }
        int mx=-1;
        for(i=0;i<=n;i++){
            v[pre[i]].pb(i);            
            mx=max(mx,pre[i]);
        }
        for(i=0;i<=mx;i++){
            if(!v[i].empty()){
                for(j=0;j<v[i].size();j++){
                    ans+=v[i][j]*j;
                    ans-=(v[i][j])*(v[i].size()-j-1);
                }
                ans-=((v[i].size())*(v[i].size()-1))/2;
            }           
        }
        cout<<ans<<'\n';
        for(i=0;i<=mx;i++){
            v[i].clear();           
        }
    }
}