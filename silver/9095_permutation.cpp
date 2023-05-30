#include <iostream>
#include <vector>

//중복 순열
using namespace std;
vector<int> v1 = {1, 2, 3};
int cnt = 0;

void permutation(int depth, int r, int sum, int targetNum){
    if(sum == targetNum) cnt++;
    if(depth >= r){
        return;
    }
    for(int i = 0; i < 3; i++){
        permutation(depth+1, r, sum+v1[i], targetNum);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        permutation(0, temp, 0, temp);
        cout<<cnt<<endl;
        cnt = 0;
    }

return 0;
}
