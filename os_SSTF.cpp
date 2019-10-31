// Author : Apaar
// Built  : 31-10-2019 09:59:50

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <unordered_map>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int a[N], n, vis[N];

int find_nearest(int cur) {
	int id = -1;
	for (int i = 0; i < n; i++) {
		if (id == -1 && !vis[i]) {
			id = i;
		}
		else if (!vis[i]) {
			if (abs(cur - a[i]) < abs(cur - a[id])) {
				id = i;
			}
		}
	}
	if (id == -1) return id;
	vis[id] = 1;
	return id;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, ans = 0, cnt = 0, sum = 0;
		int head;
		cin >> n >> head;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		i = 0;
		while (i < n) {
			int id = find_nearest(head);
			if (id == -1) break;
			ans += abs(head - a[id]);
			head = a[id];
		}
		cout << ans;
	}
}