#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    {
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;    
        cin>>n>>m;
        ll a[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                // initially all cities are disconnected
                a[i][j]=1000000;
                if(i==j){
                    a[i][j]=0;
                }
            }
        }
        for(i=0;i<m;i++){
            ll x,y,p;
            // distance from x to y is p
            cin>>x>>y>>p;
            x--;y--;
            a[x][y]=p;
            a[y][x]=p;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    // main part of algorithm as explained
                    if(a[j][i]+a[i][k]<a[j][k]){
                       a[j][k]=a[j][i]+a[i][k]; 
                    }
                }
            }
        }
        // a[i][j] repressent shortedt path between i and j;
    }
}
