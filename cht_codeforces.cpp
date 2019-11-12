/* Apaar */
// https://codeforces.com/contest/319/problem/C
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

//min cht
struct cht {
	struct Line {
		int a;
		int b;
		int val;
		long double xLeft;
		bool type;
		Line(int _a = 0 , int _b = 0) {
			a = _a;
			b = _b;
			xLeft = -1e18;
			type = 0;
			val = 0;
		}
		int valueAt(int x) const {
			return 1LL * a * x + b;
		}
		friend bool areParallel(const Line &l1, const Line &l2) {
			return l1.a == l2.a;
		}
		friend long double intersectX(const Line &l1 , const Line &l2) {
			return areParallel(l1 , l2) ? 1e18 : 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
		}
		bool operator < (const Line &l2) const {
			if (!l2.type)
				return a < l2.a;
			return xLeft > l2.val;
		}
	};
	set < Line >  hull;
	bool hasPrev(set < Line > :: iterator it) {
		return it != hull.begin();
	}
	bool hasNext(set < Line > :: iterator it) {
		return it != hull.end() && next(it) != hull.end();
	}
	bool irrelevant(const Line &l1 , const Line &l2 , const Line &l3) {
		return intersectX(l1, l3) <= intersectX(l1, l2);
	}
	bool irrelevant(set < Line > :: iterator it) {
		return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
	}
	set < Line > :: iterator updateLeftBorder(set < Line > :: iterator it) {
		if (!hasNext(it)) {
			return it;
		}
		long double val = intersectX(*it , *next(it));
		Line buf(*it);
		it = hull.erase(it);
		buf.xLeft = val;
		it = hull.insert(it, buf);
		return it;
	}
	void addLine(int a , int b) {
		Line l3 = Line(a, b);
		auto it = hull.lower_bound(l3);
		if (it != hull.end() && areParallel(*it , l3)) {
			if (it -> b > b) {
				it = hull.erase(it);
			}
			else {
				return;
			}
		}
		it = hull.insert(it, l3);
		if (irrelevant(it)) {
			hull.erase(it);
			return;
		}
		while (hasPrev(it) && irrelevant(prev(it))) {
			hull.erase(prev(it));
		}
		while (hasNext(it) && irrelevant(next(it))) {
			hull.erase(next(it));
		}
		it = updateLeftBorder(it);
		if (hasPrev(it)) {
			updateLeftBorder(prev(it));
		}
		if (hasNext(it)) {
			updateLeftBorder(next(it));
		}
	}
	int getBest(int x) {
		Line q;
		q.val = x;
		q.type = 1;
		auto bestLine = hull.lower_bound(q);
		if (bestLine == hull.end()) {
			return 1e18;
		}
		return bestLine -> valueAt(x);
	}
};
// What if minimum is required instead of maximum?
// Again, you can modify the logic... or
// you can observe that negating both slope and
// Y-intersect has the effect of mirroring about the X-axis.
// You can use the same implementation.

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n], b[n], dp[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n; i++) {
			cin >> b[i];
		}
		dp[0] = 0;
		cht hull;
		hull.addLine(b[0], dp[0]);
		for (i = 1; i < n; i++) {
			dp[i] = hull.getBest(a[i]);
			hull.addLine(b[i], dp[i]);
		}
		cout << dp[n - 1];
	}
}