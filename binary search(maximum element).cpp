int lf = 0, rt = 1e15;
while (lf <= rt) {
    int mid = (lf + rt) / 2;
    // cout<<lf<<" "<<mid<<" "<<rt<<" "<<ans<<'\n';
    if (check(mid)) {
        ans = mid;
        lf = mid + 1;
    }
    else {
        rt = mid - 1;
    }
}
cout << ans;

///////////////////////////
OR
///////////////////////

while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    if (can(mid))
        lo = mid;
    else
        hi = mid - 1;
}
cout << lo;

////////////////////////

while (l <= h) {
    ll mid = (l + h) / 2;
    if (check(mid)) {
        ans = mid;
        l = mid + 1;
    }
    else h = mid - 1;
}
cout << ans;