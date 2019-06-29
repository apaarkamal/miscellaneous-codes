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
        cin>>n;
        V<P> v(n);
        for(i=0;i<n;i++){
            cin>>v[i].F>>v[i].S;
        }
        V<V<int>> vv;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
            // construct a line passing through (x1, y1) and (x2, y2)
            // line is expressed as equation ax - by = c with constant a, b, c 
                int num=v[j].S-v[i].S;
                int den=v[j].F-v[i].F;
                int g=__gcd(num,den);
                num/=g;den/=g;
                if(den<0||(den==0&&num<0)){
                    den=abs(den);
                    num=-num;
                    //making num positive
                }
                vv.pb({num,den,num*v[i].F-den*v[i].S});                              
            }                
        }
        sort(vv.begin(), vv.end());
        vv.resize(unique(vv.begin(), vv.end())-vv.begin());
        n=vv.size();
        j=0;i=0;
        while(i<n){
            while(j<n&&vv[j][0]==vv[i][0]&&vv[i][1]==vv[j][1]){
                j++;
            }
            cnt=j-i;
            ans+=cnt*(n-cnt-i);
            i=j;
        }
        cout<<ans;
    }
}