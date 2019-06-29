// https://www.codechef.com/COCS2019/problems/ANWCC02
#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
typedef complex < double > base ;
#define PI 3.141592653589793l
void fft(vector<base> &a,bool invert){
    int i,j,n=sz(a);
    for(i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1){
            j-=bit;
        }
        j+=bit;
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    for(int len=2;len<=n;len<<= 1){
        double ang=2*PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for(i=0;i<n;i+=len){
            base w(1);
            for(j=0;j<len/2;++j){
                base u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        for(i=0;i<n;++i){
            a[i]/=n;
        }
    }
}
void multiply(const vector<int> &a,const vector<int> &b,vector <int> &res){
    vector<base> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<= 1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(size_t i=0;i<n;++i){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for(size_t i=0;i<n;++i){
        res[i]=(int)(fa[i].real()+0.5);
    }
}
int n,m,ans;
vi a,b;
void solve(){
    cin>>n>>m;
    a.resize(n);
    b.resize(m);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,m){
        cin>>b[m-i-1];
    }
    vi res;
    multiply(a,b,res);
    rep(i,m-1,n) ans=max(ans,res[i]);
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}