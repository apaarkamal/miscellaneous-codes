#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

class tictactoe {
private:
	int mat[3][3];
public:
	tictactoe() {
		memset(mat, 0, sizef(mat));
	}

	void display() {
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				cout << mat[i][j] << " ";
			}
			cout << '\n';
		}
	}

	void move_player() {
		cout << "play your move\n";
		int x, y;
		cin >> x >> y;
		x--; y--;
		mat[x][y] = 1;
		display();
	}

	void comp_move() {
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (mat[i][j] == 0) {
					mat[i][j] = 2;
					display();
					return ;
				}
			}
		}
	}

	int check() {
		int i, j;
		for (i = 0; i < 3; i++) {
			bool bl = true;
			for (j = 0; j < 3; j++) {
				if (mat[i][j] != mat[i][0]) bl = 0;
			}
			if (bl && mat[0][i] != 0) return mat[i][0];
		}
		for (i = 0; i < 3; i++) {
			bool bl = true;
			for (j = 0; j < 3; j++) {
				if (mat[j][i] != mat[0][i]) bl = 0;
			}
			if (bl && mat[0][i] != 0) return mat[0][i];
		}
		if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[1][1] != 0) return mat[0][0];
		if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[1][1] != 0) return mat[0][0];

		return -1;
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;


	}
}