#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int temp[4];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int inx = left, cnt = 0; inx <= right; inx++, cnt++) {
        arr[inx] = temp[cnt];
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        printf("left : %d, mid : %d, right : %d\n", arr[left], arr[mid], arr[right]);
        mergeSort(arr, left, mid);//left
        mergeSort(arr, mid + 1, right);//right;
        merge(arr, left, mid, right);
    }
}
int main() {
    int arr[8] = { 4, 7 ,2, 12};
    mergeSort(arr, 0, 3);
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
}
