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

const int N=400005,M=34;

struct Node{
    int lf=0,rt=0,cnt=0;
};
Node trie[N*M];
int ptr,root[N];

int insert(int prev,int num){
    int cur=ptr++;
    int temp=cur;
    trie[cur]=trie[prev];
    for(int i=M-1;i>=0;i--){
        if((num>>i)&1){
            trie[cur].rt=ptr++;
            trie[trie[cur].rt]=trie[trie[prev].rt];
            trie[trie[cur].rt].cnt=trie[trie[prev].rt].cnt+1;
            cur=trie[cur].rt;
            prev=trie[prev].rt;   
        }
        else{
            trie[cur].lf=ptr++;
            trie[trie[cur].lf]=trie[trie[prev].lf];
            trie[trie[cur].lf].cnt=trie[trie[cur].lf].cnt+1;
            cur=trie[cur].lf;
            prev=trie[prev].lf;
        }    
    }
    return temp;
}

int givekth(int prev,int cur,int k){
    int ans=0;
    for(int i=M-1;i>=0;i--){
        if(trie[trie[cur].lf].cnt-trie[trie[prev].lf].cnt>=k){
            cur=trie[cur].lf;
            prev=trie[prev].lf;
        }
        else{
            k-=trie[trie[cur].lf].cnt-trie[trie[prev].lf].cnt;
            ans+=(1<<i);
            cur=trie[cur].rt;
            prev=trie[prev].rt;
        }
    }
    return ans;
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
        cin>>n>>m;
        int a[n+1],b[n+1];
        for(i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        // cordinate compression because of negative values
        for(i=1;i<=n;i++){
            a[i]=lower_bound(b+1,b+n+1,a[i])-b+1;            
        }
        ptr=1;
        trie[0].lf=trie[0].rt=trie[0].cnt=root[0]=0;
        for(i=1;i<=n;i++){
            root[i]=insert(root[i-1],a[i]);                  
        }
        for(i=0;i<m;i++){
            int l,r,k;
            cin>>l>>r>>k;           
            // printing from b array as it will print the 
            // cordinate compressed number .
            cout<<b[givekth(root[l-1],root[r],k)-1]<<'\n';
        }
    }
}