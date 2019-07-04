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


void the_martian(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("debug.txt", "w", stdout);
    #endif
}

const int N=1000005,M=26;

struct node{
    int next[M];
    int ended=0;
    string ss;
};

node trie[N];
int ptr=1;
string s,t;
bool chk=1;

void insert(int cur,int pos,int n){
    if(pos==n){
        trie[cur].ended++;
        trie[cur].ss=s;
        return ;
    }
    if(!trie[cur].next[s[pos]-'a']){
        trie[cur].next[s[pos]-'a']=ptr++;
    }
    cur=trie[cur].next[s[pos]-'a'];
    insert(cur,pos+1,n);
}

void dfs(int cur){
    if(trie[cur].ended){
        chk=true;
        cout<<trie[cur].ss<<'\n';
    }
    for(int i=0;i<M;i++){
        if(trie[cur].next[i]){
            dfs(trie[cur].next[i]);
        }
    }
}

void go(int cur,int pos,int n){
    if(pos==n){
        dfs(cur);
        return;
    }
    if(!trie[cur].next[t[pos]-'a']){
        chk=false;
        return ;
    }
    else{
        go(trie[cur].next[t[pos]-'a'],pos+1,n);
    }
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>s;    
            insert(0,0,s.size());
        }
        cin>>m;
        while(m--){
            cin>>t;
            chk=0;
            go(0,0,t.size());
            if(!chk){
                cout<<"No suggestions\n";
            }
        }
    }
}