#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

int largemul(int a, int b, int n) { // (a * b) mod n
	// assert(0 <= a && a < n && 0 <= b && b <= n);
	int r = 0;
	for (; b; b >>= 1, a <<= 1) {
		if (a >= n) a -= n;
		if (b & 1) {
			r += a;
			if (r >= n) r -= n;
		}
	}
	return r;
}

int fastexp(int a, int b, int n) { // compute (a ^ b) mod n
	int ret = 1;
	for (; b; b >>= 1, a = largemul(a, a, n))
		if (b & 1) ret = largemul(ret, a, n);
	return ret;
}

bool mrtest(int n) { // miller rabin big primality test
	if (n == 1) return false;
	int d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		s++;
		d /= 2;
	}
	for (int j = 0; j < (int)A.size(); j++) {
		if (A[j] > n - 1) continue;
		int ad = fastexp(A[j], d, n);
		if (ad % n == 1) continue;
		bool notcomp = false;
		for (int r = 0; r <= max(0LL, s - 1); r++) {
			int rr = fastexp(2, r, n);
			int ard = fastexp(ad, rr, n);
			if (ard % n == n - 1) {notcomp = true; break;}
		}
		if (!notcomp) {
			return false;
		}
	}
	return true;
}


int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0;
		cin >> n;
		if (mrtest(n)) {
			cout << "Prime\n";
		}
		else {
			cout << "No Prime\n";
		}
	}
}