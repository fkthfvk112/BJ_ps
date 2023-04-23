#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n1, n2;
    priority_queue<int> pq;
    cin>>n1>>n2;

    for(int i = 0; i < n1; i++){
        int num;
        cin>>num;
        pq.push(-num);
    }
    for(int i = 0; i < n2; i++){
        int num;
        cin>>num;
        pq.push(-num);
    }
    while(!pq.empty()){
        cout<<-pq.top()<<" ";
        pq.pop();
    }

return 0;
}
