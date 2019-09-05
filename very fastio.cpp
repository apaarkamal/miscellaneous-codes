int read() {
	char c = gc();
	while ((c < '0' || c > '9') && c != '-') c = gc();
	int ret = 0, neg = 0;
	if (c == '-') neg = 1, c = gc();
	while (c >= '0' && c <= '9') {
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return neg ? -ret : ret;
}