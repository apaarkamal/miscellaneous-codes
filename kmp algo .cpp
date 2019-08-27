// https://www.codechef.com/problems/CDVA1606
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

void buildlpsarray(string pat,int *lps){
    int m=pat.size(),i=0,j=0;
    lps[0]=0;
    i=1;
    while(i<m){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            j++;i++;
        }
        else{
            if(j==0){
                lps[i]=0;
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }
    // lps[m-1] indicates length of 
    // longest suffix which is also a prefix
    // of course whole string will be longest 
    // suffix which is prefix
}

void buildlpsarray1(string pat,int *lps){
    lps[0]=-1;
    int n=pat.size();
    for(int i=0;i<n;i++) {
        int j = i - 1;
        while (j>=0 && pat[lps[j]+1]!=pat[i]){
            j = lps[j];  
        } 
        if (j ==-1) {
            lps[i] = -1;
        } 
        else{
            lps[i] = lps[j] + 1;    
        }
    }
    for(int i=0;i<n;i++){
        lps[i]++;            
    }
}

int kmp(string txt,string pat,int *lps){
    int ans=0,m=pat.size(),i=0,j=0,n=txt.size();
    while(i<n){
        if(txt[i]==pat[j]){
            i++;j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
        if(j==m){
            ans++;
            j=lps[j-1];
        }
    }
    return ans==0?-1:ans;
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
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>m>>k;
        string txt,pat;
        cin>>txt>>pat;
        pat.resize(k);
        m=k;
        int *lps=new int[m];
        buildlpsarray1(pat,lps);
        cout<<kmp(txt,pat,lps)<<'\n';
    }
}