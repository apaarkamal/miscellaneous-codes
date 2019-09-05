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
#define db(x) cout <<#x<<": "<<x<<'\n';

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const int N = 100005, M = 22;
char s[1000010]; int n, p[1000010];
int32_t main()
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)if (s[i] == '1')p[n - 1 - i] = 1;
    for (int i = 0, j; i < n + 2;)
            if (!p[i])i++; else
        {
            j = i; while (p[j])j++;
            if (j - i >= 2) {for (int k = i + 1; k < j; k++)p[k] = 0; p[j] = 1;}
            i = j;
        }
    int S = 0;
    for (int i = 0; i < n + 2; i++)if (p[i] != 0)S++;
    // for(int i=0;i<n+2;i++)cout<<p[i]<<" ";
    printf("%lld\n", S);
    return 0;
}