// Author : Apaar
// Built  : 31-10-2019 10:03:28

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, i, j, k;
	cin >> n >> m;
	int alloc[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> alloc[i][j];
		}
	}

	int max[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> max[i][j];
		}
	}

	int avail[m];

	for (i = 0; i < m; i++) {
		cin >> avail[i];
	}

	for (int j = 0; j < m; j++) {
		for (i = 0; i < n; i++) {
			avail[j] -= alloc[i][j];
		}
	}

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++) {
						avail[y] += alloc[i][y];
					}
					f[i] = 1;
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		cout << "P-> " << ans[i] + 1 << '\n';
	}
	return 0;
}
