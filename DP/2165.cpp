#include <algorithm>
#include <iostream>
#include <vector>
//���� MAX ���� X MAX�� �������.

using namespace std;
int main(void){
    int dp[10010];
    vector<int> value;
    int n;
    int qqt;
    cin>>n;

    for(int i = 0; i < 2; i++){
        cin>>qqt;
        value.push_back(qqt);
        if(i==0){
            dp[i] = qqt;
            continue;
        }
        if(i==1){
            dp[i] = dp[i-1] + qqt;
            continue;
        }
    }

    for(int i = 2; i < n; i++){
        cin>>qqt;
        value.push_back(qqt);
        dp[i] = max(dp[i-2], value[i-1] + dp[i-3]) + qqt;
        dp[i] = max(dp[i], dp[i-1]);//���� �� ã�� �κ�
    }



    long long int ans = 0;

    for(int i = 0; i < n; i++){
        if(dp[i] > ans){
            ans = dp[i];
        }
    }
    cout<<ans;
    return 0;
}
