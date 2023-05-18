#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt = 0;
vector<pair<int, int>> hanoiV;
void hanoi(int n, int start, int middle, int end){
    if(n == 1){
        hanoiV.push_back({start, end});
        cnt++;
        return;
    }
    hanoi(n-1, start, end, middle);
    hanoiV.push_back({start, end});
    cnt++;
    hanoi(n-1, middle, start, end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    hanoi(n, 1, 2 ,3);
    cout<<cnt<<'\n';
    for(auto v:hanoiV){
        cout<<v.first<<" "<<v.second<<'\n';
    }

return 0;
}
