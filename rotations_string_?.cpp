//sartaj and challenge hackererath
// check if two arrays are rotation of each other or not
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 100005;

int lpsarray(vector<int> a, vector<int> b) {
	a.pb(-1);
	for (auto x : b) a.pb(x);
	int i, j, n = a.size();
	vector<int> lps(n, 0);
	lps[0] = 0;
	i = 1; j = 0;
	while (i < n) {
		if (a[i] == a[j]) {
			lps[i] = j + 1;
			j++; i++;
		}
		else {
			if (j == 0) {
				lps[i] = 0;
				i++;
			}
			else {
				j = lps[j - 1];
			}
		}
	}
	return lps[n - 1];
}

bool check(vector<int> a, vector<int> b) {
	int pos = lpsarray(a, b);
	int n = b.size();
	for (int i = 0, sz = 0, k = b.size() - pos; sz < n; i++, sz++) {
		if (a[i] != b[k]) return false;
		k++;
		k %= n;
	}
	return true;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n], b[n];
		vector<int> ao, ae, bo, be;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			if (i & 1) ao.pb(a[i]);
			else ae.pb(a[i]);
		}
		for (i = 0; i < n; i++) {
			cin >> b[i];
			if (i & 1) bo.pb(b[i]);
			else be.pb(b[i]);
		}
		if ((check(ae, be) && check(ao, bo)) || (check(ae, bo) && check(ao, be))) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
		cout << '\n';
	}
}