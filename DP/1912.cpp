#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxSubArray(vector<int> arr, int n) {
    vector<int> dp;
    dp.resize(n);

    int result = dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        if (dp[i] > result) result = dp[i];
    }
    return result;
}

int main() {
    vector<int> arr;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    cout << maxSubArray(arr, n);

    return 0;
}
