#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    string a = " ";
    string b = " ";
    string temp1, temp2;

    cin>>temp1>>temp2;
    a += temp1;
    b += temp2;

    vector<vector<int>> dp;
    for(int i = 0; i < a.size()+1; i++){
        for(int j = 0; j < b.size()+1; j++){
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    dp[0][0] = 0;
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[j] == b[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            if(dp[i][j] > ans){
                ans = dp[i][j];
            }
        }
    }
    cout<<ans;
return 0;
}
