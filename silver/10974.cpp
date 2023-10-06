#include <iostream>
#include <vector>

using namespace std;
vector<int> v1;
vector<int> ansVec;
vector<int> visited;

void printAns(int r){
    for(int i = 0; i < r; i++){
        cout<<ansVec[i]<<" ";
    }
    cout<<'\n';
}
void permutation(int depth, int n, int r){
    if(depth == r){
        printAns(r);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            ansVec[depth] = v1[i];
            permutation(depth+1, n, r);
            visited[i] = false;
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        v1.push_back(i);
    }
    ansVec.resize(n);
    visited.resize(n);
    permutation(0, n, n);

return 0;
}
