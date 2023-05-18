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
    cout << endl;
}

void make_pattern(int startRow, int endRow, int startCol, int endCol, vector<vector<char>>& pattern) {
    if (endRow - startRow < 2 || endCol - startCol < 2) return;

    int itemSize = (endRow - startRow + 1) / 3;
    pair<int, int> row1 = { startRow, startRow + itemSize - 1 };
    pair<int, int> row2 = { startRow + itemSize, startRow + (itemSize * 2) - 1 };
    pair<int, int> row3 = { startRow + (itemSize * 2), endRow };

    pair<int, int> col1 = { startCol, startCol + itemSize - 1 };
    pair<int, int> col2 = { startCol + itemSize, startCol + (itemSize* 2) - 1 };
    pair<int, int> col3 = { startCol + (itemSize * 2), endCol };

    //cout << "Row : star, end" << startRow << " " << endRow << endl;
    //cout << "Col : start, end" << startCol << " " << endCol << endl;

    vector<pair<int, int>> itemRows = { row1, row2, row3 };
    vector<pair<int, int>> itemCols = { col1, col2, col3 };

    for (int i = startRow + itemSize; i < startRow + itemSize * 2; i++) {
        for (int j = startCol + itemSize; j < startCol + itemSize * 2; j++) {
            pattern[i][j] = ' ';
        }
    }
    //print_v(pattern);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            make_pattern(itemRows[i].first, itemRows[i].second, itemCols[j].first, itemCols[j].second, pattern);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> pattern(n, vector<char>(n, '*'));
    make_pattern(0, n - 1, 0, n - 1, pattern);
    print_v(pattern);

    return 0;
}
