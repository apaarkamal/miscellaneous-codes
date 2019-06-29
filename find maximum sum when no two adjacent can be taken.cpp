
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,n;
        cin>>n;
        int a[n],dp[n],par[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            dp[i]=0;
        }
        dp[0]=max(dp[0],a[0]);
        if(n==1){
            cout<<a[0]<<'\n';
            continue;
        }
        dp[1]=max({dp[1],dp[0],a[1]});
        for(i=2;i<n;i++){
            dp[i]=max({dp[i],dp[i-2]+a[i],dp[i-1]});                
        }
        for(i=n-1;i>=0;i--){
            if(dp[i]==dp[i-1]){
                continue;
            }
            else if(a[i]>0){
                cout<<a[i];
                i--;
            }  
        }
        cout<<'\n';
    }
}