// https://www.spoj.com/problems/SUBXOR/
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

const int N=100005,M=22;

struct trie
{   
    struct trie *lf=NULL,*rt=NULL;
    int cnt=0;
};

trie *head;

void insert(int num){
    trie *cur=head;
    for(int i=M-1;i>=0;i--){
        if((num>>i)&1){
            if(cur->rt==NULL){
                cur->rt=new trie();
            }
            cur=cur->rt;
            cur->cnt++;
        } 
        else{
            if(cur->lf==NULL){
                cur->lf=new trie();
            }
            cur=cur->lf;
            cur->cnt++;
        }
    }
}

int give(trie *cur,int num,int k,int lvl){
    int ans=0;
    if(cur==NULL||lvl<0){
        return ans;
    }
    int numbit=(num>>lvl)&1,kbit=(k>>lvl)&1;
    if(numbit&&kbit){
        if(cur->rt){
            ans+=cur->rt->cnt;
        }
        ans+=give(cur->lf,num,k,lvl-1);
    }
    else if(numbit&&(!kbit)){
        ans+=give(cur->rt,num,k,lvl-1);
    }
    else if((!numbit)&&kbit){
        ans+=give(cur->rt,num,k,lvl-1);
        if(cur->lf){
            ans+=cur->lf->cnt;
        }
    }
    else{
        ans+=give(cur->lf,num,k,lvl-1);
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
    int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>k;
        int a[n];
        head=new trie();
        insert(0);
        for(i=0;i<n;i++){
            cin>>a[i];
            cnt^=a[i];
            ans+=give(head,cnt,k,M-1);
            insert(cnt);
        }
        cout<<ans<<'\n';
    }
}