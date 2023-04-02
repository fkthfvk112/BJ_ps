#include <iostream>
#define MOD 1000000000

using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long int dp[101][11] = {0, };

    int n;
    cin>>n;

    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    };

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1]%MOD;
            }
            else if(j == 9){
                dp[i][j] = dp[i-1][j-1]%MOD;
            }
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) %MOD;
        }
    }

    long long int result = 0;
    for(int i= 0; i < 10; i++){
        result += dp[n][i];
    }
    cout<<result%MOD;


return 0;
}
