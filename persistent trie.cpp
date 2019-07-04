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

const int N=500005,M=22;

struct Node{
    int lf,rt,cnt;
};
Node trie[N*
    M*4];
int ptr=1,root[N];
int a[N];

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

int maxxor(int prev,int cur,int num){
    int ans=0;
    for(int i=M-1;i>=0;i--){
        if((num>>i)&1){
            if(trie[trie[prev].lf].cnt<trie[trie[cur].lf].cnt){
                prev=trie[prev].lf;
                cur=trie[cur].lf;
            }
            else{
                ans+=(1<<i);
                prev=trie[prev].rt;
                cur=trie[cur].rt;
            }
        }   
        else{
            if(trie[trie[prev].rt].cnt<trie[trie[cur].rt].cnt){
                ans+=(1<<i);
                prev=trie[prev].rt;
                cur=trie[cur].rt;
            }
            else{
                prev=trie[prev].lf;
                cur=trie[cur].lf;
            }
        }
    }
    return ans;
}

int numberofintergerslessthanorequal(int prev,int cur,int num){
    int ans=0;
    for(int i=M-1;i>=0;i--){
        if((num>>i)&1){
            ans+=(trie[trie[cur].lf].cnt-trie[trie[prev].lf].cnt);
            cur=trie[cur].rt;
            prev=trie[prev].rt;
        }             
        else{
            cur=trie[cur].lf;   
            prev=trie[prev].lf;
        }           
    }
    ans+=trie[cur].cnt-trie[prev].cnt;
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
        cin>>m;
        n=1;
        trie[0].lf=trie[0].rt=trie[0].cnt=root[0]=a[0]=0;
        for(i=0;i<m;i++){
            int t;
            cin>>t;
            if(t==0){
                cin>>a[n];
                root[n]=insert(root[n-1],a[n]);
                n++;                  
            }
            else if(t==1){
                int l,r,k;
                cin>>l>>r>>k;           
                cout<<maxxor(root[l-1],root[r],k)<<'\n';
            }
            else if(t==2){
                cin>>k;
                n-=k;
            }
            else if(t==3){
                int l,r,x;
                cin>>l>>r>>x;
                cout<<numberofintergerslessthanorequal(root[l-1],root[r],x)<<'\n';
            }   
            else{
                int l,r,k;
                cin>>l>>r>>k;      
                cout<<givekth(root[l-1],root[r],k)<<'\n';   
            }
        }
    }
}