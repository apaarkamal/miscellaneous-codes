#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> 
new_data_set; 

const int N=100005;

class BIT
{
public:
    int a[N];
    void add(int x, int val)
    {
        x++;
        while (x < N)
        {
            a[x] += val;
            x += (x&-x);
        }
    }
    int sum(int x)
    {
        int ret = 0;
        x++;
        while (x)
        {
            ret += a[x];
            x -= (x&-x);
        }
        return ret;
    }
}bit;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // int t;
    // cin>>t;
    // while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;  
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            bit.add(i,a[i]);
            sum=bit.sum(i);
            cout<<sum<<'\n';
        }  
        
    }
}