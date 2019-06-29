// https://codeforces.com/gym/100570/problem/F
// https://www.codechef.com/FEB19A/problems/TRDST
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>L[101000], E[101000];
vector<long long>Len[101000];
vector<vector<long long> >Len2[101000];
int n, C[101000], Q[101000], par[101000], head, tail, pp[101000], pc[101000];
long long D[101000];
bool chk[101000], v[101000];
void BFS(int a){
    int i, x;
    head = tail = 0;
    Q[++tail] = a, v[a] = true; D[tail] = 0;
    while (head < tail){
        x = Q[++head];
        for (i = 0; i < E[x].size(); i++){
            if (!chk[E[x][i]] && !v[E[x][i]]){
                v[E[x][i]] = true;
                Q[++tail] = E[x][i];
                par[tail] = head;
                D[tail] = D[head] + L[x][i];
            }
        }
    }
    for (i = 1; i <= tail; i++)v[Q[i]] = false;
}
int get_mid(){
    int i, M, x, d;
    for (i = tail; i >= 1; i--){
        C[i]++;
        C[par[i]] += C[i];
    }
    d = C[1] / 2, M = C[1] + 1;
    for (i = 1; i <= tail; i++){
        if (C[i] > d && M > C[i])M = C[i], x = Q[i];
        C[i] = 0;
    }
    return x;
}
void Do(int a, int p, int c){
    int i, mid, j;
    BFS(a);
    if (tail == 1){
        Len[a].push_back(0);
        if (p)pp[a] = p, pc[a] = c;
        return;
    }
    mid = get_mid();
    chk[mid] = true;
    if (p)pp[mid] = p, pc[mid] = c;
    for (i = 0; i < E[mid].size(); i++){
        if (!chk[E[mid][i]]){
            Do(E[mid][i], mid, i);
        }
    }
    chk[mid] = false;
    BFS(mid);
    for (i = 1; i <= tail; i++)Len[mid].push_back(D[i]);
    sort(Len[mid].begin(), Len[mid].end());
    chk[mid] = true;
    Len2[mid].resize(E[mid].size());
    for (i = 0; i < E[mid].size(); i++){
        if (!chk[E[mid][i]]){
            BFS(E[mid][i]);
            for (j = 1; j <= tail; j++){
                Len2[mid][i].push_back(D[j] + L[mid][i]);
            }
            sort(Len2[mid][i].begin(), Len2[mid][i].end());
        }
    }
    chk[mid] = false;
}
int Gap(int a, long long d){
    int sz = Len[a].size();
    int b = 0, e = sz - 1, res = -1, mid;
    while (b <= e){
        mid = (b + e) >> 1;
        if (Len[a][mid] <= d)res = mid, b = mid + 1;
        else e = mid - 1;
    }
    return res + 1;
}
int Gap2(int a, int k, long long d){
    int sz = Len2[a][k].size();
    int b = 0, e = sz - 1, res = -1, mid;
    while (b <= e){
        mid = (b + e) >> 1;
        if (Len2[a][k][mid] <= d)res = mid, b = mid + 1;
        else e = mid - 1;
    }
    return res + 1;
}
int Dep[101000], par2[17][101000];
long long DL[101000];
void DFS(int a, int pp){
    Dep[a] = Dep[pp] + 1;
    par2[0][a] = pp;
    int i;
    for (i = 0; i < E[a].size(); i++){
        if (E[a][i] == pp)continue;
        DL[E[a][i]] = DL[a] + L[a][i];
        DFS(E[a][i], a);
    }
}
void Make_List(){
    int i, j;
    for (i = 0; i < 16; i++)for (j = 1; j <= n; j++)par2[i + 1][j] = par2[i][par2[i][j]];
}
int LCA(int a, int b){
    if (Dep[a] < Dep[b])swap(a, b);
    int d = Dep[a] - Dep[b], i = 0;
    while (d){
        if (d & 1)a = par2[i][a];
        i++; d >>= 1;
    }
    for (i = 16; i >= 0; i--){
        if (par2[i][a] != par2[i][b])a = par2[i][a], b = par2[i][b];
    }
    if (a != b)a = par2[0][a];
    return a;
}
long long dist(int a, int b){
    return DL[a] + DL[b] - DL[LCA(a, b)] * 2;
}

ll check(ll a,ll d){
        // scanf("%d%lld", &a, &d);
        ll b = a;
        ll t = -1;
        ll Res = 0;
        while (a){
            ll d2 = d - dist(a, b);
            if (d2 >= 0){
                Res += Gap(a, d2);
                if (t != -1) Res -= Gap2(a, t, d2);
            }
            t = pc[a];
            a = pp[a];
        }
        return Res;
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int i, a, b, c, Q, t, Res;
    long long d, S, d2;
    ll k[101000],ans[101000];
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%lld",&k[i]);
    }
    for (i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
        L[a].push_back(1);
        L[b].push_back(1);
    }

    Do(1, 0, 0);
    DFS(1, 0);
    Make_List();

    for(i=1;i<=n;i++){
        ll lo=0,hi=n;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(n-check(i,mid)<k[i])
                hi=mid;
            else
                lo=mid+1;
        }
        cout<<lo-1<<" ";
    }

}