#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;

void ans(int depth, int parent) {
    if(depth == m){
        for(auto ans:dq){
            cout<<ans<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = parent+1; i <= n; i++){
        dq.push_back(i);
        ans(depth+1, i);
        dq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ans(0, 0);
    return 0;
}
