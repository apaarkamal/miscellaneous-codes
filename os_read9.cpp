/* Apaar */

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	string line;
	ifstream myfile("input.txt");
	int space = 0, alphabets = 0, special_chars = 0, numericals = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			for (int i = 0; i < line.size(); i++) {
				if (line[i] >= '0' && line[i] <= '9') numericals++;
				else if (line[i] == ' ') space++;
				else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) alphabets++;
				else special_chars++;
			}
		}
		myfile.close();
	}
	cout << "alphabets -> " << alphabets << '\n';
	cout << "numericals -> " << numericals << '\n';
	cout << "special_chars -> " << special_chars << '\n';
	cout << "space -> " << space << '\n';
}