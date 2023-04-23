#include <iostream>
#include <queue>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    priority_queue<pair<int, int>> pq;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int first, second;
        cin>>first>>second;
        pq.push(make_pair(-first, -second));
    }

    while(!pq.empty()){
        cout<<-pq.top().first<<" "<<-pq.top().second<<"\n";
        pq.pop();
    }

return 0;
}
