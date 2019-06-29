pair<ll,ll> give(ll x1,ll y1,ll x2,ll y2){
    if(x1>x2||y1>y2){
        return {0,0};
    }
    ll bl=0;
    ll wt=0;
    ll m=y2-y1+1;
    ll n=x2-x1+1;
    bl=m/2;
    wt=m-bl;
    ll bl1=wt,wt1=bl;
    bl=bl*((n+1)/2);
    wt=wt*((n+1)/2);
    bl1=bl1*(n/2);
    wt1=wt1*(n/2);
    bl+=bl1;
    wt+=wt1;
    if((x1+y1)%2==0){
        return {bl,wt};
    }
    else{
        return {wt,bl};
    }
}