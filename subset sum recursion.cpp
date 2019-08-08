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

int val[N];

bool is_sum(int pos,int n,int sum){
    if(pos<0) return false;
    if(sum<0) return false;
    if(sum==0) return true;
    return is_sum(pos-1,n,sum)||is_sum(pos-1,n,sum-val[pos]);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>sum;
        for(i=0;i<n;i++){
            cin>>val[i];           
        }
        if(is_sum(n-1,n,sum)){
            cout<<"true";
        }
        else{
            cout<<"false";
        }
    }
}