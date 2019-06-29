#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N=100005;

int sett(int a,int n){
    return a+pow(2,n);
}

int unsett(int a,int n){
    return a-pow(2,n);
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        int l,r;
        cin>>l>>r;
        int curbit=63;
        int a=l,b=r;
        for(i=63;i>=0;i--){
            int curpow=pow(2,i);
            if(((!(curpow&a))&&(!(curpow&b)))){
                // db(a,b);
                if(sett(a,i)>=l&&sett(a,i)<=r){
                    a=a+curpow;
                }
            }
            if((curpow&a)&&(curpow&b)){
                if(unsett(b,i)>=l&&unsett(b,i)<=r){
                    b=b-curpow;
                }
            }
        }
        a=a^b;
        cout<<a;
    }
}