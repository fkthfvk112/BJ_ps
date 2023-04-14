#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int bi[100][100];
    int n;
    int r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            if (i == j || j == 0) {
                bi[i][j] = 1;
            }
            else bi[i][j] = bi[i - 1][j] + bi[i - 1][j - 1];
        }
    }
    cout << bi[n][r];

    return 0;
}
