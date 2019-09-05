#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 2420304
#define MaxNode 1020304
#define MD 1000000007

int now = 0, go[MaxN][26];
void ins(int t, char *s) {
    if (s[0] == '$') return ;
    if (go[t][s[0] - 'a']) ins(go[t][s[0] - 'a'], s + 1);
    else ins(go[t][s[0] - 'a'] = ++now, s + 1);
}

int ans = 0, k, n, can[MaxN];
void dfs(int t, int now) {
    if (now > k || t == 0) return ; ++ans;
    For(i, 0, 25) dfs(go[t][i], now + can[i]);
}

int A[1550][1550]; char s[MaxN];
int main() {
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    scanf("%s", s + 1); n = strlen(s + 1); s[n + 1] = '$';
    scanf("\n"); For(i, 0, 25) scanf("%c", &can[i]), can[i] -= 48, can[i] = 1 - can[i];
    cin >> k;
    now = 1; For(i, 1, n) ins(1, s + i);
    dfs(1, 0);
    cout << ans - 1 << endl;
    return 0;
}
