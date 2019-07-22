#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

const int N=100005;

int pr[N];
vector<int> primes;

void seive(){
    int i,j;
    for(i=2;i<N;i++){
        if(!pr[i]){
            primes.pb(i);
            for(j=i;j<N;j+=i){
                pr[j]++;
            }
        }
    }
}


int32_t main()
{
    the_martian();
    seive();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        for(i=3;i<=1000;i++){
            auto it=upper_bound(primes.begin(), primes.end(),i);
            if(*it-i>=i/2){
                cout<<i<<'\n';;
            }
        }

    }
}