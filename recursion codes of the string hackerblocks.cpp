#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;
string s;
vector<string> ans;

char give(int x) {
    return (char)(x + 'a' - 1);
}

void go(int pos, string ss) {
    if (pos == s.size()) {
        ans.pb(ss);
        return;
    }
    go(pos + 1, ss + give(s[pos] - '0'));
    if (pos + 1 < s.size()) {
        int num = (s[pos] - '0') * 10 + (s[pos + 1] - '0');
        if (num <= 26 && num >= 0) {
            go(pos + 2, ss + give(num));
        }
    }
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, cnt = 0, sum = 0;
        cin >> s;
        go(0, "");
        cout << "[";
        for (i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i == ans.size() - 1) continue;
            cout << ", ";
        }
        cout << "]";
    }
}