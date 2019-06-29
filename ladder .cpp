// http://codeforces.com/problemset/problem/279/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
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
        cin>>n>>m;
        ll a[n];
        for(i=0;i<n;i++){
          cin>>a[i];
        }
        ll L[n],R[n];
        L[0]=0;
        for(i=1;i<n;i++){
          if(a[i]<=a[i-1]){
            L[i]=L[i-1];
          }
          else{
            L[i]=i;
          }
        }
        R[n-1]=n+1;
        for(i=n-2;i>=0;i--){
          if(a[i]<=a[i+1]){
            R[i]=R[i+1];
          }
          else{
            R[i]=i;
          }
        }
        for(i=0;i<n;i++){
          cout<<L[i]<<" ";
        }
        cout<<'\n';
        for(i=0;i<n;i++){
          cout<<R[i]<<" ";
        }
        cout<<'\n';
        while(m--){
          ll l,r;
          cin>>l>>r;
          l--;r--;
          if(L[r]<=R[l]){
            cout<<"Yes\n";
          }
          else{
            cout<<"No\n";
          }
        }
    }
}
///////////////////////////////////////////
#include <cstdio>
using namespace std;

int a[111111];
int dp0[111111];
int dp1[111111];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dp0[0] = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i - 1] >= a[i])
            dp0[i] = dp0[i - 1] + 1;
        else
            dp0[i] = 1;
    }
    dp1[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] <= a[i + 1])
            dp1[i] = dp1[i + 1] + 1;
        else
            dp1[i] = 1;
    }

    for(int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        if(dp1[l] + dp0[r] >= r - l + 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}