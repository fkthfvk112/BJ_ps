#include <iostream>
#include <vector>
#include <string>
//각 켤 수 있는 램프를 모두 더한 후, 하나 씩 뺏을 때 0이 나오면 불가, 아니면 가능

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> lampTable(n, vector<int>(m, 0));
    vector<int> summedTable(m, 0);

    for(int i = 0; i < n; i++){
        int lampTotalN;
        cin>>lampTotalN;
        for(int j = 0; j < lampTotalN; j++){
            int lampN;
            cin>>lampN;
            lampTable[i][lampN-1] += 1;
            summedTable[lampN-1] += 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(summedTable[j] - lampTable[i][j] > 0){
                cnt++;
            }
        if(cnt >= m) ans = 1;
        }
    }

    cout<<ans;
return 0;
}
