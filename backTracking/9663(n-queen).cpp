#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int ans = 0;
int board[15];
bool isPromissing(int level){
    for(int i = 0; i < level; i++){
        if(board[i] == board[level]||abs(board[level] - board[i]) == level - i){
            return false;
        }
    }
    return true;
}

void nQeen(int x){
    if(x == N)
        ans++;
    else{
        for(int i = 0; i < N; i++){
            board[x] = i;
            if(isPromissing(x)){
                nQeen(x+1);
            }
        }
    }
}

int main(){
    cin>>N;
    nQeen(0);
    cout<<ans;

}
