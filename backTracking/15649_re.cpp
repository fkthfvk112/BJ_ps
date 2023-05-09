#include <iostream>

#define MAX 9
using namespace std;

int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };
int n, m;
void ans(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            ans(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ans(0);

    return 0;
}
