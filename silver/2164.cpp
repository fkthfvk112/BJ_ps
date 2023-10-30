#include <iostream>
#include <queue>

using namespace std;
int main(void){
    int n;
    queue<int> q;
    cin>>n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int cnt = 0;
    while(1){
        cnt++;
        if(q.size() == 1){
            cout<<q.front();
            break;
        }
        if(cnt == 1){
            q.pop();
        }
        else if(cnt==2){
            q.push(q.front());
            q.pop();
        }
        cnt = cnt%2;
    }
    return 0;
}
