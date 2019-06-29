#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define IOS 


#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


const int N=100005;

void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

bool comp(P a,P b){
    if(a.F==b.F){
        return a.S<b.S;
    }
    return a.F>b.F;
}

int NC2(int x){
    return ((x)*(x-1))/2;
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        int a[n];
        vector<P> v;
        for(i=0;i<n;i++){
            cin>>a[i];
            v.pb({a[i],i+1});
        }
        sort(v.begin(), v.end(),comp);
        set<int> St;
        St.insert(0);
        St.insert(n+1);
        i=0;
        while(i<n){
            auto end=St.lower_bound(v[i].S);
            auto start=end;
            start--;
            j=i+1;
            while(j<n&&v[i].F==v[j].F&&v[j].S<*end){
                j++;
            }
            cnt=j-i;
            ans+=NC2(cnt);
            if(*start!=0){
                ans+=cnt;
            }
            if(*end!=n+1){
                ans+=cnt;
            }
            for(k=i;k<j;k++){
                St.insert(v[k].S);    
            }
            i=j;
        }
        cout<<ans;
    }
}