#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<int>> matrixPower(const vector<vector<int>>& A, long long B, int N) {
    if (B == 1) {
        return A;
    }
    if (B % 2 == 0) {
        vector<vector<int>> halfPower = matrixPower(A, B / 2, N);
        return multiply(halfPower, halfPower, N);
    } else {
        vector<vector<int>> halfPower = matrixPower(A, (B - 1) / 2, N);
        return multiply(A, multiply(halfPower, halfPower, N), N);
    }
}

int main() {
    int N;
    long long B;
    cin >> N >> B;
    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = matrixPower(matrix, B, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
