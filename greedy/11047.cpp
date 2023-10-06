#include <iostream>
#include <stack>

using namespace std;
int main(){

    int n, k;
    cin>>n>>k;
    stack<int> coins;
    for(int i = 0; i < n; i++){
        int coin;
        cin>>coin;
        coins.push(coin);
    }

    int cnt = 0;
    while(!coins.empty() || k != 0){
        int coin = coins.top();
        cnt += k/coin;
        k %= coin;
        coins.pop();
    }

    cout<<cnt;
return 0;
}
