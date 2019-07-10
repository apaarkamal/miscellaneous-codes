#include<bits/stdc++.h>
using namespace std;

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
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        cout<<s<<'\n';
        while(next_permutation(s.begin(), s.end())){
            cout<<s<<'\n';
        }
    }
}