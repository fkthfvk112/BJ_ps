#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, k;
    int value;
    vector<int> v1;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>value;
        v1.push_back(value);
    }
    int cnt = 0;
    while(k > 0){
        for(int i = v1.size()-1; i >= 0; i--){
            if(v1[i] <= k){
                cnt += k/v1[i];
                k = k%v1[i];
            }
        }
    }
    cout<<cnt;
return 0;
}
