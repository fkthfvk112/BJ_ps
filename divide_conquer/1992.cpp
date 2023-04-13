#include <iostream>
#include <string>
#include <vector>

using namespace std;

string quadTree(vector<vector<int>> arr, int startRow, int endRow,int startCol, int endCol) {
	int rowMid = (startRow + endRow) / 2;
	int colMid = (startCol + endCol) / 2;
	if (startRow == endRow || startCol == endCol) {
		int rIndex = startRow;
		int lIndex = startCol;
		return to_string(arr[startRow][startCol]);
	}
	string a = quadTree(arr, startRow, rowMid, startCol, colMid);
	string b = quadTree(arr, startRow, rowMid, colMid + 1, endCol);
	string c = quadTree(arr, rowMid + 1, endRow, startCol, colMid);
	string d = quadTree(arr, rowMid +1, endRow, colMid + 1, endCol);
	if (a == b && b == c && c == d && a[0]!='(') {
		return  a;
	}
	else {
		return "(" + a + b + c +  d + ")";
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v1(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		for (int j = 0; j < n; j++) {
			v1[i][j] = s1[j] - '0';
		}
	}
	string answer = quadTree(v1, 0, n-1, 0, n-1);
	cout << answer;
return 0;
}
