#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

typedef complex < double > base ;
#define PI 3.141592653589793l
void fft(vector<base> &a, bool invert) {
	int i, j, n = a.size();
	for (i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) {
			j -= bit;
		}
		j += bit;
		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (i = 0; i < n; i += len) {
			base w(1);
			for (j = 0; j < len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (i = 0; i < n; ++i) {
			a[i] /= n;
		}
	}
}
void multiply(const vector<int> &a, const vector<int> &b, vector <int> &res) {
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max((int)a.size(), (int)b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);
	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i < n; ++i) {
		fa[i] *= fb[i];
	}
	fft(fa, true);
	res.resize(n);
	for (size_t i = 0; i < n; ++i) {
		res[i] = (int)(fa[i].real() + 0.5);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		string s, t;
		cin >> s >> t;
		n = s.size();
		m = t.size();
		vector<int> p1(n, 0), p2(m, 0), p3;
		for (i = 0; i < n; i++) {
			p1[i] = (s[i] - '0');
		}
		for (i = 0; i < m; i++) {
			p2[i] = (t[i] - '0');
		}
		reverse(p1.begin(), p1.end());
		reverse(p2.begin(), p2.end());
		multiply(p1, p2, p3);
		k = p3.size();
		int carry = 0;
		string ress;
		for (i = 0; i < k; i++) {
			sum = carry;
			sum += p3[i];
			int rem = sum % 10;
			ress.pb(rem + '0');
			sum /= 10;
			carry = sum;
		}
		while (carry > 0) {
			int rem = carry % 10;
			ress.pb(rem + '0');
			carry /= 10;
		}
		reverse(ress.begin(), ress.end());
		for (i = 0; i < (int)(ress.size()); i++) {
			if (cnt == 0 && ress[i] == '0') continue;
			cnt = 1;
			cout << ress[i];
		}
		if (!cnt) cout << 0;
		cout << '\n';
	}
}