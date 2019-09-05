#include<bits/stdc++.h>
using namespace std;
void subsequences(string a, string b, int be, int i, int n)
{
    if (be == n)
    {
        cout << b << endl;
        return;
    }
    // exclude the ith character
    subsequences(a, b, be + 1, i, n);
    // include the ith character
    b[i] = a[be];
    subsequences(a, b, be + 1, i + 1, n);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    {
        string a;
        cin >> a;
        int n = a.size();
        string b;
        string c = " ";
        for (int i = 0; i < n; i++) {
            b += c;
        }
        subsequences(a, b, 0, 0, n);
    }
}
