// https://www.hackerearth.com/practice/algorithms/graphs/min-cut/practice-problems/algorithm/parity-game-icpc-11/editorial/
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+3;
int c[N], d[N];
int main(){
    int n, q, l, r;
    scanf("%d %d",&n,&q);
    for(int i=0;i<q;++i){
        scanf("%d %d",&l,&r);
        ++c[l]; --c[r+1]; 
        ++d[l]; ++d[r+1];
    }
    int re=c[1];
    for(int i=2;i<=n;++i){
        c[i]+=c[i-1];
        re=min(re,c[i]);
        re=min(re,d[i]);
    }
    printf("%d\n",re);
    return 0;
}