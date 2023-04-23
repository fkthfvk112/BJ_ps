#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n1, n2;
    vector<int> v1;
    cin>>n1>>n2;

    for(int i = 0; i < n1; i++){
        int num;
        cin>>num;
        v1.push_back(num);
    }
    for(int i = 0; i < n2; i++){
        int num;
        cin>>num;
        v1.push_back(num);
    }
    sort(v1.begin(), v1.end());
    for(auto v:v1){
        cout<<v<<" ";
    }
return 0;
}
