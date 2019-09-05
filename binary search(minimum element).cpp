int binsearch(int lo, int hi)
{
    //lo is included
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

ll lf = -1, rt = 1e15;
while (lf + 1 < rt) {
    else {
        ans
        ll mid = (lf + rt) / 2;
        ld ansd = (ld)(sum + (mid * k)) / (ld)(n + mid);
        if ((ll)(ansd + 0.5) >= k) {
            rt = mid;
        }
        else {
            lf = mid;
        }
    }
    cout << rt;



//////////////end points included
    int lf = 0, rt = min(n - x, m - y), ans = -1;
    while (lf <= rt) {
        int mid = (lf + rt) / 2;
        // db(lf,rt,mid);
        if (check(v, x, y, x + mid, y + mid)) {
            ans = (mid + 1) * (mid + 1);
            rt = mid - 1;
        }
        else {
            lf = mid + 1;
        }
    }
    cout << ans << '\n';