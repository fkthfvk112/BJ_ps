#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    vector<int> nv;
    int dp[100];
    int t, n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin>>t;
    for(int i =0; i < t; i++){
        cin>>n;
        for(int i = 4; i <= n; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        cout<<dp[n]<<'\n';
    }

return 0;
}
