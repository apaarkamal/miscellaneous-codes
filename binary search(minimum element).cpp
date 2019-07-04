int binsearch(int lo, int hi)
{
        //lo is included
	    while(lo<hi)
	    {
	        int mid=(lo+hi)/2;
	        if(check(mid))
	            hi=mid;
	        else
	            lo=mid+1;
	    }
	    return lo;
}

		ll lf=-1,rt=1e15;
        while(lf+1<rt){
        else{
            ans
            ll mid=(lf+rt)/2;
            ld ansd=(ld)(sum+(mid*k))/(ld)(n+mid);
            if((ll)(ansd+0.5)>=k){
                rt=mid;
            }
            else{
                lf=mid;
            }
        }
        cout<<rt;