#include<bits/stdc++.h>

using namespace std;

void permutations(string s, int cur, int n) {
    if (cur == n) {
        cout << s << '\n';
        return ;
    }
    int i;
    for (i = cur; i < n; i++) {
        swap(s[i], s[cur]);
        permutations(s, cur + 1, n);
        swap(s[i], s[cur]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //  code starts
    string s;
    cin >> s;
    int n = s.size();
    permutations(s, 0, n);
}
