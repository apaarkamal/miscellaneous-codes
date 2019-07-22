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
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

const int N=1000005;

int anss[N];
string s;

struct node{
    node* next[26];
    int cnt=0;
    node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;       
        }
    }
};

void insert(node* root){
    for(int i=0;i<s.size();i++){
        if(root->next[s[i]-'a']==NULL){
            root->next[s[i]-'a']=new node();
        }
        root=root->next[s[i]-'a'];
    }
    root->cnt++;
}

int NC2(int x){
    return (x*(x-1))/2;   
}

void dfs(node *root,int dep){
    int ans=0;
    for(int i=0;i<26;i++){
        if(root->next[i]!=NULL){
            dfs(root->next[i],dep+1);
            root->cnt+=root->next[i]->cnt;
            ans-=NC2(root->next[i]->cnt);
        }          
    }
    ans+=NC2(root->cnt);
    // db(ans,dep);
    anss[dep]+=ans;
}

int32_t main()
{
    the_martian();
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        node* root=new node();
        for(i=0;i<n;i++){
            cin>>s;
            insert(root);
        }
        dfs(root,0);
        for(i=0;i<N;i++){
            ans+=anss[i];                      
        }
        cout<<ans<<'\n';
    }
}