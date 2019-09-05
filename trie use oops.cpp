#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fio ios_base::sync_with_stdio(false)
#define pdl cout << "*" << endl
#define MOD 1000000007
#define INF 1000000000
#define INFLL 1000000000000000000ll
#define m_p make_pair
#define p_b push_back
#define ff first
#define ss second
#define lli long long int
#define ulli unsigned long long int
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
#define lop(i,a,b) for(lli i=a;i<b;i++)
#define lopr(i,a,b) for(lli i=a;i>=b;i--)

lli exp_mod(lli a, lli b, lli mod) {
    lli ret = 1;
    while (b) {
        if (b % 2 == 1) { ret *= a; ret %= mod; }
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}
lli inverse_mod(lli a, lli mod) {
    return exp_mod(a, mod - 2, mod);
}
lli modInverse(lli a, lli m) {
    lli m0 = m;
    lli y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        lli q = a / m;
        lli t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
vector<int> prefix_array(string st) {
    int n = st.length();
    vector<int> Z(n, 0);
    int j = 0;
    lop(i, 1, n) {
        j = Z[i - 1];
        while (j > 0 && st[j] != st[i]) {
            j = Z[j - 1];
        }
        if (st[i] == st[j]) { j++; }
        Z[i] = j;
    }
    return Z;
}

struct node {
    node *num[20];
    int tot = 0;
    node() {
        lop(i, 0, 20) { num[i] = NULL; }
        tot = 0;
    }
}*root, *temp;
int x, ans, n, q;
void insert(string st) {
    temp = root;
    lop(i, 0, st.length()) {
        if (st[i] >= '0' && st[i] <= '9') { x = st[i] - '0'; }
        else { x = st[i] - 'A'; x += 10; }
        if (temp->num[x] == NULL) {
            temp->num[x] = new node();
        }
        temp = temp->num[x];
        temp->tot++;
    }
}
int find_ans(string st) {
    temp = root;
    ans = 0;
    lop(i, 0, st.length()) {
        if (st[i] >= '0' && st[i] <= '9') { x = st[i] - '0'; }
        else { x = st[i] - 'A'; x += 10; }
        if (temp->num[x] == NULL) { return 0; }
        temp = temp->num[x];
        ans = temp->tot;
    }
    return ans;
}
int main() {
    fio;
    cin.tie(NULL);
    root = NULL;
    root = new node();
    cin >> n >> q;
    string st;
    lop(i, 0, n) {
        cin >> st;
        insert(st);
    }
    while (q--) {
        cin >> st;
        cout << find_ans(st) << endl;
    }
    return 0;
}