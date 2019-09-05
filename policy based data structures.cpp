#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const int N = 100005, M = 22;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        new_data_set S;
        for (i = 0; i < n; i++) {
            int x;
            cin >> x;
            S.insert(x);
        }
        cout << *S.find_by_order(2) << '\n'; // element at  second index in the set
        cout << S.order_of_key(2); // at as lower bound to aa key provided
    }
}