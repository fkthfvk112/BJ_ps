#include <iostream>

using namespace std;

int main(){
    int n, sum =0;
    string num;
    cin>>n>>num;
    for(int i = 0; i < n; i++){
        int tempNum = (int)num[i]-'0';
        sum += tempNum;
    }
    cout<<sum<<endl;

return 0;
}
