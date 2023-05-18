#include <iostream>
#include <vector>

using namespace std;

void print_v(vector<vector<char>> pattern) {
    for (auto a : pattern) {
        for (auto b : a) {
            cout << b;
        }
        cout << endl;
    }
}

void make_pattern(int startRow, int endRow, int startCol, int endCol, vector<vector<char>>& pattern) {
    if (endRow - startRow < 2 || endCol - startCol < 2) return;

    int itemSize = (endRow - startRow + 1) / 3;
    for (int i = startRow + itemSize; i < startRow + itemSize * 2; i++) {
        for (int j = startCol + itemSize; j < startCol + itemSize * 2; j++) {
            pattern[i][j] = ' ';
        }
    }
    int midRow = (startRow + endRow)/ 2;
    int midCol = (startCol + endCol)/ 2;

    make_pattern(startRow, midRow, startCol, midCol, pattern);//1
    make_pattern(startRow, midRow, midCol, endCol, pattern);//2
    make_pattern(midRow, endRow, startCol, midCol, pattern);//3
    make_pattern(midRow, endRow, midCol, endCol, pattern);//4
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> pattern(n, vector<char>(n, '*'));
    make_pattern(0, n - 1, 0, n - 1, pattern);
    print_v(pattern);

    return 0;
}
