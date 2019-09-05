#include<bits/stdc++.h>

using namespace std;

int main()
{
	int i, n;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool check = 1;
	for (i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i - 1]) check = 0;
	}
	cout << (check ? "YES, PALINDROME" : "NOT, PALINDROME");
}