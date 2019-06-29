#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll grid[300][300],z=0;
ll dx[8]={2,2,-2,-2,1,1,-1,-1};
ll dy[8]={1,-1,1,-1,2,-2,2,-2};
bool issafe(ll x,ll y,ll n){
  if(x<n&&x>=0&&y<n&&y>=0&&!grid[x][y]){
    return true;
  }
  return false;
}
void print(ll n){
	ll i,j;
	for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        cout<<grid[i][j]<<" ";
      }cout<<"\n";
    }
}
void fun(ll row,ll col,ll n,,ll m,ll cnt){
  ll i,j;
  if(cnt==n*m){
    cout<<
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cout<<grid[i][j]<<" ";
      }cout<<"\n";
    }
    exit(0);
  }
  // cout<<row<<" "<<col<<'\n';
  for(i=0;i<8;i++){
  	ll xx,yy;
  	xx=row+dx[i];
  	yy=col+dy[i];
    if(issafe(xx,yy,n)){
      grid[xx][yy]=cnt+1;
      fun(xx,yy,n,cnt+1);
      grid[xx][yy]=0;
    }
  }
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
      cout<<"Case #"<<tt++<<": ";
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;    
        cin>>n;
        grid[0][0]=1;
        fun(0,0,n,1ll);
        if(!z){
          cout<<"IMPOSSIBLE\n";
        }
    }
}
