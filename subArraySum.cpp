#include <iostream>
#include <vector>
//divid and conquer
using namespace std;
int get_sum_left(int mid, int left, vector<int> arr){
    int maxSum = 0;
    int sumAll = 0;
    for(int i = mid; i >= left; i--){
        sumAll += arr[i];
        if(maxSum < sumAll){
            maxSum = sumAll;
        }
    }
    return maxSum;
}

int get_sum_right(int mid, int right, vector<int> arr){
    int maxSum = 0;
    int sumAll = 0;
    for(int i = mid+1; i <= right; i++){
        sumAll += arr[i];
        if(maxSum < sumAll){
            maxSum = sumAll;
        }
    }
    return maxSum;
}

int get_array_maxSum(int left, int right, vector<int> arr){
    if(right-left <= 0) return arr[left];//요소가 하나일 때 종료
    int mid = (left + right)/2;
    int sumMax = 0;
    int sum_left_right = get_sum_left(mid, left, arr) + get_sum_right(mid, right, arr);
    sumMax = max(sum_left_right,max(get_array_maxSum(left, mid, arr), get_array_maxSum(mid+1, right, arr)));
    return sumMax;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    cout<<get_array_maxSum(0, n-1, arr);
return 0;
}
