#include <iostream>

using namespace std;
int arr[] = {1, 2, 3, 4, 5};
int ans[100];
int visit[100];
void printArr(int r){
    for(int i = 0; i < r; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void permu(int cnt, int n, int r){
    if(cnt == r){
        printArr(r);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            ans[cnt] = arr[i];
            visit[i] = true;
            permu(cnt+1, n, r);
            visit[i] = false;
        }
    }

}
int main(){
    int arr[] = {4, 5, 3};
    permu(0, 3, 3);//cnt r


return 0;
}
