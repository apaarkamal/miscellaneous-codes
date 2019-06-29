#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i,j,k,n,m,cnt=0,sum=0;
        cin>>n>>m>>k;
        string s[n];
        for(i=0;i<n;i++){
            cin>>s[i];
        }
        vector<pair<ll,ll>> ans;
        pair<ll,ll> start;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(s[i][j]=='.'){
                    start={i,j};
                    break;
                }
            }
            if(s[i][j]=='.'){
                break;
            }
        }
        ll vis[n][m];
        memset(vis,0,sizeof(vis));
        queue<pair<ll,ll>> Q;
        Q.push(start);
        ans.push_back(start);
        vis[start.first][start.second]=1;
        while(!Q.empty()){
            pair<ll,ll> cur=Q.front();
            Q.pop();
            ll x=cur.first;
            ll y=cur.second;
            for(i=0;i<4;i++){
                ll xx=x+dx[i];
                ll yy=y+dy[i];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]=='.'&&!vis[xx][yy]){
                    Q.push({xx,yy});
                    cout<<xx<<" "<<yy<<'\n';
                    vis[xx][yy]=1;
                    ans.push_back({xx,yy});
                }
            }
        }
        reverse(ans.begin(),ans.end());
        for(i=0;i<k;i++){
            s[ans[i].first][ans[i].second]='X';
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cout<<s[i][j];
            }
            cout<<'\n';
        }
    }
}
