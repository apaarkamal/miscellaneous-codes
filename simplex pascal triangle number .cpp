//https://en.wikipedia.org/wiki/Pentatope_number#/media/File:Pascal_triangle_simplex_numbers.svg
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll fact[2000006];
ll modinverse(ll a, ll m)
{
    ll m0=m;
    ll y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        int q=a/m;
        int t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0)
    {
      x+=m0;
    }
    return x;
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fact[0]=1;
    for(ll i=1;i<2000006;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;    
        cin>>n>>m>>k;
        ll free=n-(k*(m-1)+1);
        free++;
        // cout<<free<<'\n';
        if(free<=0){
            cout<<0<<'\n';
        }
        else{
            ans=fact[free+m-2];
            // cout<<ans<<'\n';
            // m is depth and free is column number
            ans*=modinverse(fact[m-1],mod);
            ans%=mod;
            ans*=modinverse(fact[free-1],mod);
            ans%=mod;
            cout<<ans<<'\n';
        }
    }
}