#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'fountainActivation' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int fountainActivation(vector<int> a) {
	int n = a.size();
	vector<int> right_most(n, 0);

	for (int i = 0; i < n; i++) {
		int left = max(i - a[i], 0);
		int right = min(i + (a[i] + 1), n);
		right_most[left] = max(right_most[left], right);
	}

	int ans = 1;
	int right = right_most[0], next_right = 0;
	for (int i = 0; i < n; i++) {
		next_right = max(next_right, right_most[i]);
		if (i == right) {
			ans++;
			right = next_right;
		}
	}

	return ans;
}

int main()