#include <iostream>

using namespace std;
int main(){
    long long int dp[100] = {0,};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    int n;
    cin>>n;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
return 0;
}
