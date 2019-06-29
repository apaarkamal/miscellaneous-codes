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
        string s,t;
        int a[n]={};
        cin>>s>>t;
        int ss=0,tt=0;
        for(i=0;i<n;i++){
            a[i]=s[i]-'a'+t[i]-'a';
        }
        for(i=0;i<n;i++){
            if(a[i]%2==0){
                a[i]/=2;
            }           
            else{
                a[i]/=2;
                a[i+1]+=26;
            }   
        }
        for(i=n-1;i>=1;i--){
            a[i-1]+=a[i]/26;  
            a[i]%=26;
        }
        a[0]%=26;
        for(i=0;i<n;i++){
            cout<<(char)('a'+a[i]);           
        }
    }
}