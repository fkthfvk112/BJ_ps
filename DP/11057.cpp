#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int dp[10001][10] = {0,};
    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            int sum = 0;
            for(int k = 0; k <= j; k++){
                sum += dp[i-1][k];
            }
            dp[i][j] = sum%10007;
        }
    }

    int result = 0;
    for(int i = 0; i < 10; i++){
        result += dp[n][i];
    }
    cout<<result%10007;
return 0;
}
