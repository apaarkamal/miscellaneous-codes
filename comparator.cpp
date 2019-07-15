sort(ALL(order_s), [&](int lhs, int rhs) {return si[lhs] < si[rhs];});

sort(v.begin(), v.end(), [](const ar<int, 3> &a, const ar<int, 3> &b) {
		return a[2]<b[2];
});
