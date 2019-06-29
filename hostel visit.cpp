#include <iostream>
#include <queue>
#include<math.h>
#define ll long long int
using namespace std;
int main() {
    ll x,y,t,k,d;  
    priority_queue<ll> pq;
    cin>>t>>k;
    while(t--){
        cin>>d;
        if(d==2){
            if(pq.size()>k){
                pq.pop();
            }
            cout<<pq.top()<<'\n';
        }
        else{
            cin>>x>>y;
            ll sum=pow(x,2)+pow(y,2);
            pq.push(sum);
        }
    }
}
