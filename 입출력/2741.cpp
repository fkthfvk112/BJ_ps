#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, num = 1;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<num<<"\n";
        num++;
    }

return 0;
}

//endl을 사용했더니 시간 초과가 나왔다.
//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); c스타일과 c++스타일의 입출력을 끊는다
//https://www.acmicpc.net/problem/15552
