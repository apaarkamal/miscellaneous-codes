#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

mt19937_64 rnd(228);

const int N = 250000 + 7;
const int K = 20;

int dep[N];

ll h[N];
ll a[N];
vector <int> g[N];
ll ok[N];
int tin[N], tout[N];
ll fenw[N];
int st[N][K];

int tt = 0;

void dfs(int v, int pr) {
  tin[v] = tt++;
  st[v][0] = (pr == -1 ? v : pr);
  for (int i = 1; i < K; i++) {
    st[v][i] = st[st[v][i - 1]][i - 1];
  }
  for (int to : g[v]) {
    if (to != pr) {
      dep[to] = dep[v] + 1;
      dfs(to, v);
    }
  }
  tout[v] = tt;
}

bool par(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (par(a, b)) {
    return a;
  }
  for (int i = K - 1; i >= 0; i--) {
    if (!par(st[a][i], b)) {
      a = st[a][i];
    }
  }
  return st[a][0];
}

ll get(int x) {
  ll rr = 0;
  for (;x >= 0; x = (x & (x + 1)) - 1) {
    rr ^= fenw[x];
  }
  return rr;
}

void inc(int x, ll y) {
  for (; x < N; x = (x | (x + 1))) {
    fenw[x] ^= y;
  }
}

int main() {
    ios_base:: sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
  for (int i = 0; i < N; i++) {
    h[i] = rnd();
    ok[i] = h[i];
    cout<<h[i]<<'\n';
    if (i) ok[i] ^= ok[i - 1];
  }
  int t;
  cin >> t;
  while (t--) {
    memset(fenw, 0, sizeof fenw);
    tt = 0;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      a[i] = h[x];
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
      inc(tin[i], a[i]);
      inc(tout[i], a[i]);
    }
    for (int i = 0; i < q; i++) {
      int t;
      cin >> t;
      if (t == 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int c = lca(u, v);
        int len = dep[u] + dep[v] - 2 * dep[c];
        if ((get(tin[u]) ^ get(tin[v]) ^ a[c]) == ok[len]) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      } else {
        int u, x;
        cin >> u >> x;
        u--, x--;
        inc(tin[u], a[u]);
        inc(tout[u], a[u]);
        a[u] = h[x];
        inc(tin[u], a[u]);
        inc(tout[u], a[u]);
      }
    }
  }
}
