#include <iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int dp[1000];
    int dp_o[1000];
    cin>>n;
    dp[1] = 1; dp_o[1] = 1;
    dp[2] = 3; dp_o[2] = 2;
    dp[3] = 5; dp_o[3] = 3;



    for(int i = 4; i <= n; i++){
        dp[i] = 2*dp[i-2] + dp[i-1]%10007;
    }

    cout<<dp[n];

return 0;
}
