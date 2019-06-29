#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll grid[300][300],z=0,cnt=0;
bool issafe(ll row,ll col,ll n,ll m,ll x,ll y){
    return row<n&&col<m&&grid[row][col]==0&&x!=row&&y!=col&&(row-col)!=(x-y)&&(row+col)!=(x+y);
}
void nqueen(ll row,ll col,ll n,ll m,vector<pair<ll,ll>> v){
    if(z) return;
  if(cnt==n*m){
    cout<<"POSSIBLE\n";
    for(auto x:v){
        cout<<x.first+1<<" "<<x.second+1<<'\n';
    }
    cout<<'\n';
    z=1;
    return;
  }
  int i,j;
  for(i=0;i<n;i++){
      for(ll j=0;j<m;j++){
        if(issafe(i,j,n,m,row,col)){
          grid[i][j]=1;
          cnt++;
          v.push_back({i,j});
          nqueen(i,j,n,m,v);
          v.pop_back();
          cnt--;
          grid[i][j]=0;
        }
      }
  }
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<tt++<<": ";z=0;
        ll i,j,k,n,m,sum=0;    
        cin>>n>>m;
        for(i=0;i<n;i++){
          for(j=0;j<m;j++){
            grid[i][j]=0;
          }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                vector<pair<ll,ll>> v;
                v.push_back({i,j});
                grid[i][j]=1;
                cnt++;
                nqueen(i,j,n,m,v);
                cnt--;
                grid[i][j]=0;
            }   
        }
        if(!z){
            cout<<"IMPOSSIBLE\n";
        }
    }
}