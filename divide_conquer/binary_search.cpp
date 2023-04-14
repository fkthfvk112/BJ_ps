#include <stdio.h>

int binarySearch(int arr[], int left, int right, int findingValue) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    printf("현재 미드 값 : %d\n", arr[mid]);
    if (findingValue == arr[mid])return mid;
    if (findingValue < arr[mid]) return binarySearch(arr, left, mid - 1, findingValue);
    else return binarySearch(arr, mid + 1, right, findingValue);
}
int main() {
    int arr[] = { 2, 4, 6, 8, 9, 11, 12, 13, 15, 16, 22, 45, 87, 89 };
    int left = 0;
    int right = 13;
    printf("인덱스 위치 : %d", binarySearch(arr, left, right, 45));
    return 0;
}
