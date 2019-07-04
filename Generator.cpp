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

const ll N=100005;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "w", stdout);
    ll t;
    t=400000;
    cout<<t<<endl;
    while(t--){   
        int n=rand()%10+1;
        cout<<n<<'\n';
    }
    return 0;
}