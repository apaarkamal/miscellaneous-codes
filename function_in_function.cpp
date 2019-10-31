auto add_edge = [&](int u, int v, int val) {
	int cur = u;
	string s = to_string(val);
	for (j = 0; j < s.size(); j++) {
		int to;
		if (j == s.size() - 1) to = v;
		else to = nw++;
		gr[cur][s[j] - '0'].pb(to);
		cur = to;
	}
};

////////////////////////////////////////////

sort(ord.begin(), ord.end(), [&] (int i, int j) {
	return cs[i] > cs[j];
});