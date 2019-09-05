#include <bits/stdc++.h>

using namespace std;

#define READ()      freopen("in.txt","r",stdin)
#define WRITE()     freopen("out.txt","w",stdout)
#define sf(n)       scanf("%d",&n)
#define sl(x)       scanf("%I64d",&x)
#define lsf(n)      scanf("%lld", &n)
#define pb(n)       push_back(n)
#define mem(x,y)    memset(x,y,sizeof(x))
#define D(x)        cout << #x << " = " << x << endl
#define CHKRTE      assert(false)
#define YOLO        cout << "YOLO" << endl
#define NL          printf("\n")
#define EPS         1e-10
#define INF         INT_MAX
#define MAX         INT_MAX
#define MOD         1000000007
#define LL          long long
#define endl        "\n"
#define pi          2.0*acos(0.0)
#define cnd         tree[idx]
#define lnd         tree[left]
#define rnd         tree[right]
#define callLeft    left,st,mid
#define callRight   right,mid+1,ed

int len; /// total len
int digitUp[20];
void toDigUpper(LL x)
{
    stack <int> stk;
    while (x > 0)
    {
        stk.push(x % 10); x /= 10;
    }
    if (stk.empty())stk.push(0);
    while (!stk.empty())
    {
        digitUp[len++] = stk.top(); stk.pop();
    }
}


LL dp[17][17][2][2][2];
LL rec(int pos, bool noLimitOfPrvPos, bool startHoise, int backPos, bool boroNisi)
{
    if (pos > backPos)
    {
        if (!noLimitOfPrvPos && boroNisi)return 0;
        return 1;
    }

    if (dp[pos][backPos][noLimitOfPrvPos][startHoise][boroNisi] != -1)
        return dp[pos][backPos][noLimitOfPrvPos][startHoise][boroNisi];

    int limit;
    if (noLimitOfPrvPos == true)limit = 9;
    else limit = digitUp[pos];

    LL ret = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (startHoise == 0 && i == 0)
        {
            ret += rec(pos + 1, noLimitOfPrvPos || i < digitUp[pos], 0, backPos, boroNisi);
        }
        else if (pos == backPos)
        {
            ret += rec(pos + 1, noLimitOfPrvPos || i < digitUp[pos], startHoise | i > 0, backPos, boroNisi);
        }
        else
        {
            if (i == digitUp[backPos])
            {
                ret += rec(pos + 1, noLimitOfPrvPos || i < digitUp[pos], startHoise | i > 0,
                           backPos - 1, boroNisi);
                continue;
            }

            ret += rec(pos + 1, noLimitOfPrvPos || i < digitUp[pos], startHoise | i > 0,
                       backPos - 1, i > digitUp[backPos]);
        }
    }
    dp[pos][backPos][noLimitOfPrvPos][startHoise][boroNisi] = ret;
    return ret;
}

LL getAns(LL x)
{
    if (x < 0)return 0;
    if (x < 10)return x + 1;
    mem(dp, -1);
    len = 0;
    toDigUpper(x);
    return rec(0, false, 0, len - 1, false);
}


int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    sf(t);
    int TC = 0;
    while (t--)
    {
        LL a, b;
        lsf(a);
        lsf(b);

        if (a > b)swap(a, b);

        LL ret = getAns(b) - getAns(a - 1);

        printf("Case %d: %lld\n", ++TC, ret);
    }
}

