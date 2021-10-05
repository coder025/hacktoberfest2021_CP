#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	// for gettin ginput from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif
	int t;
	cin >> t;
	while (t--) {
		int cx = 0, co = 0, c_ = 0;
		char arr[3][3];

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'X') cx++;
				if (arr[i][j] == 'O') co++;
				if (arr[i][j] == '_') c_++;
			}
		// cout << cx << " " << co << " " << c_ << endl;
		int winx = 0, wino = 0;

		if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X') winx = 1;
		if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X') winx = 1;
		if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X') winx = 1;
		if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') winx = 1;
		if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') winx = 1;
		if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X') winx = 1;
		if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X') winx = 1;
		if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X') winx = 1;


		if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O') wino = 1;
		if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O') wino = 1;
		if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O') wino = 1;
		if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') wino = 1;
		if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O') wino = 1;
		if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O') wino = 1;
		if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O') wino = 1;
		if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O') wino = 1;

		// cout << winx << " " << wino << endl;
		if ((winx == 1 && wino == 1) || ((cx - co) < 0) || (cx - co) > 1) cout << 3 << endl;  //not possible
		else if ( cx == 0 && co == 0 && c_ == 9) cout << 2 << endl;	 // move left
		else if (winx == 1 && wino == 0 && cx > co) cout << 1 << endl;	 //X wins
		else if (winx == 0 && wino == 1 && cx == co) cout << 1 << endl; //O wins
		else if (winx == 0 && wino == 0 && c_ == 0) cout << 1 << endl; //draw
		else if (winx == 0 && wino == 0 && c_ > 0) cout << 2 << endl; // move left
		else cout << 3 << endl;  // not possible

	}
	return 0;
}