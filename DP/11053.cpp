#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> values;
    vector<int> dp(n, 0);
    int ele;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        values.push_back(ele);
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(values[i] > values[j] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
            }
        }
        if(max < dp[i]){
            max = dp[i];
        }
    }

    cout<<max;


    return 0;
}
