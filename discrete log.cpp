// https://codeforces.com/contest/1182/problem/E
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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

int mod = 1000000007;
inline int powr(int a, int b,int m){
    int x = 1 % m;
    while(b){
        if(b & 1) x = (x*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return x;
}

// loga(b)%mod
int discreteLog(int a, int b, int m)
{
    a %= m, b %= m;
    if(b == 1)
        return 0;
    int cnt = 0;
    long long t = 1;
    for(int curg=__gcd(a, m);curg!=1;curg=__gcd(a, m))
    {
        if(b % curg)
            return -1;
        b /= curg, m /= curg, t = (t * a / curg) % m;
        cnt++;
        if(b == t)
            return cnt;
    }

    gp_hash_table<int, int> hash;
    int mid = ((int)sqrt(1.0 * m) + 1);
    long long base = b;
    for(int i=0;i<mid;i++)
    {
        hash[base] = i;
        base = base * a % m;
    }

    base = powr(a, mid, m);
    long long cur = t;
    for(int i=1;i<=mid+1;i++)
    {
        cur = cur * base % m;
        auto it = hash.find(cur);
        if(it != hash.end())
            return i * mid - it->second + cnt;
    }
}

const int sz=5;
struct Mat
{
    int m[sz][sz];

    Mat()
    {
        memset(m, 0, sizeof m);
    }

    void eye()
    {
        for(int i=0; i<sz; i++)
            m[i][i] = 1;
    }

    Mat operator* (const Mat &a) const
    {
        Mat r;
        for(int i=0; i<sz; i++)
            for(int j=0; j<sz; j++)
                for(int k=0; k<sz; k++)
                    r.m[i][j] = (r.m[i][j] + m[i][k] * a.m[k][j]) % mod;
        return r;
    }
};

Mat solve(int e)
{
    Mat r, a;
    r.eye();
    a.m[0][0]=a.m[0][1]=a.m[0][2]=a.m[0][3]=a.m[1][0]=a.m[2][1]=1;
    a.m[3][3]=1;a.m[3][4]=2;a.m[4][4]=1;
    while(e)
    {
        if(e & 1)
            r = r * a;
        a = a * a;
        e >>= 1;
    }
    return r;
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
        int i,j,k,m,ans=0,cnt=0,sum=0;
        int f1,f2,f3,c,n;
        cin>>n>>f1>>f2>>f3>>c;
        f1=discreteLog(5,f1,mod);
        f2=discreteLog(5,f2,mod);
        f3=discreteLog(5,f3,mod);
        c=discreteLog(5,c,mod);
        mod--;
        Mat answer=solve(n-3);
        V<int> v={f3,f2,f1,(2*c)%mod,c};
        for(i=0;i<sz;i++){
            ans+=(answer.m[0][i]*v[i])%mod;            
        }
        mod++;
        cout<<powr(5,ans,mod);
    }
}