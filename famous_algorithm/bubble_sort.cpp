#include <iostream>

using namespace std;
int main(){
    int n[] = {1, 2, 7, 3, 8, 4, 9};
    for(int i = 0; i < 7; i++){
        for(int j = 6; j > i+1; j--){
            if(n[j] < n[j-1]){
                int temp = n[j];
                n[j] = n[j-1];
                n[j-1] = temp;
            }
        }
    }

    for(auto a:n){
        cout<<a<<" ";
    }
return 0;
};
