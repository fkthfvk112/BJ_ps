#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[1000];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    int n;
    cin>>n;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cout<<dp[n];

return 0;
}
