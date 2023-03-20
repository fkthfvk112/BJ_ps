#include <iostream>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[1000000];

    int n;
    cin>>n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1]+1;
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
    }
    cout<<dp[n];

    return 0;
}
