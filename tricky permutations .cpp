#include<bits/stdc++.h>
using namespace std;

int main()
{
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