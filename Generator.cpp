#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const ll N = 100005;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, m, i, j;
    string s = "BW";
    n = 2000; m = 2000;
    cout << n << " " << m << '\n';
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << s[rand() % 2];
        }
        cout << '\n';
    }
    return 0;
}