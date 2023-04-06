#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int dpAlgo(long long int dp[2][100000], vector<vector<int>> sticker, int n){
    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[1][0] + sticker[0][1];
    dp[1][1] = sticker[0][0] + sticker[1][1];
    for(int col = 2; col < n; col++){
        for(int row = 0; row < 2; row++){
            if(row == 0){
                dp[row][col] = max(max(dp[0][col-2], dp[1][col-2]), dp[1][col-1]) + sticker[row][col];
            }
            if(row == 1){
                dp[row][col] = max(max(dp[0][col-2], dp[1][col-2]), dp[0][col-1]) + sticker[row][col];
            }
        }
    }
    return max(dp[0][n-1], dp[1][n-1]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int testCnt, colCnt;
    cin>>testCnt;
    long long int dp[2][100000] = {{0,}};
    for(int testCase = 0; testCase < testCnt; testCase++){
        cin>>colCnt;
        vector<vector<int>> sticker(2, vector<int>(colCnt, 0));
        for(int row = 0; row < 2; row++){
            for(int col = 0; col < colCnt; col++){
                int temp;
                cin>>temp;
                sticker[row][col] = temp;
            }
        }
        cout<<dpAlgo(dp, sticker, colCnt)<<"\n";
    }

return 0;
}
