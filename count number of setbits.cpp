#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//  code starts
	int n, set_bits = 0;
	cin >> n;
	while (n != 0) {
		if (n % 2 == 1) { // odd numbebr
			set_bits++;
		}
		n /= 2;
	}
	cout << set_bits;
}
