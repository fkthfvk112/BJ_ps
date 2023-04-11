#include <iostream>

using namespace std;
int location(int arr[], int low, int high, int x){
    int mid;
    if(low > high){
        return 0;
    }
    else{
        mid = (low+high)/2;
        if(x == arr[mid]) return mid;
        else if(x < arr[mid]) return location(arr, low, mid-1, x);
        else return location(arr, mid+1, high, x);
    }
}
using namespace std;
int main(){
    int n[] = {2, 5, 11, 13, 15, 16, 17, 22, 45};
    int result = location(n, 0, 9, 16);
    cout<<result;
return 0;
};
