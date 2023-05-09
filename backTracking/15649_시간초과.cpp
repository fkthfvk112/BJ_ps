#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//find함수 때문에 시간초과가 나는 듯 하다
using namespace std;

void ans(int n, int m, int parent, string ansString) {
    if (m == 0) {
        cout << ansString << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if(parent == i) continue;
        if(ansString.find(to_string(i)) != string::npos) continue;
        string anSt;
        if(parent == 0) anSt = to_string(i);
        else anSt = ansString + " " + to_string(i);
        ans(n, m - 1, i, anSt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    ans(n, m, 0, "");
    return 0;

}
