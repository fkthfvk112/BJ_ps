#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v1;

    int n;

    string sNum;
    int maxV = 1000000;
    int minV =  -1000000;
    cin>>n;
    cin.ignore();
    getline(cin, sNum);
    string buffer;
    for(auto s:sNum){
        buffer += s;
        if(s == ' '){
            v1.push_back(stoi(buffer));
            buffer= "";
        }
    }
    v1.push_back(stoi(buffer));

    sort(v1.begin(), v1.end());
    cout<<v1.front()<<" "<<v1.back();

return 0;
}
