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


#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N=(1<<20),M=20;
const int K=(1<<20)-1;

const int mod = 1000000007;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((int) x) * y) % mod;}
inline int powr(int a, int b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int dp[N];

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,sum=0,cnt=0;
        cin>>n;
        int mask=0;
        for(i=0;i<n;i++){
            cin>>mask;
            dp[mask]++;
        }
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                if((1<<i)&j){
                    dp[(1<<i)^j]+=dp[j];
                }
            }
        }
        for(i=0;i<N;i++){
            if(__builtin_popcount(i)&1){
                ans=sub(ans,(powr(2,dp[i])-1+mod)%mod);
            }
            else{
                ans=add(ans,(powr(2,dp[i])-1)%mod);
            }
        }
        cout<<ans;
    }
}