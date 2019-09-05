ll get(ll x) {
	return (x == p[x] ? x : (p[x] = get(p[x])));
}

void unite(ll x, ll y) {
	x = get(x);
	y = get(y);
	if (x != y) {
		p[x] = y;
	}
}
//initially everyone is parent of itself