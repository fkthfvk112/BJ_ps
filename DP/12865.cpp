#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    vector<pair<int, int>> items;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp;
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        dp[i].resize(k + 1);
        items.push_back(make_pair(weight, value));
    }
    dp[0][0] = 0;
    for (int j = 0; j <= k; j++) {
        if (j >= items[0].first) {
            dp[0][j] = items[0].second;
        }
    }

    for (int i = 1; i < n; i++) {//item
        for (int j = 1; j <= k; j++) {//weight
            if (j >= items[i].first) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i].first] + items[i].second);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 1][k];
    return 0;
}
