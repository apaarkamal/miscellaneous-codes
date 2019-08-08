#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(x) cout <<#x<<": "<<x<<'\n';

const int N=100005;

// memoisation
int memo[N];

int fib(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(memo[n]!=-1){
        return memo[n];
    }
    memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        memset(memo,-1,sizeof(memo));
        cout<<fib(50);

    }
}