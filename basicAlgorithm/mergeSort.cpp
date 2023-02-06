/**
* merge sort
*/

#include <iostream>
using namespace std;

int temp[8];

void merge(int list[], int left, int mid, int right) {
    int i,j,k;
    i = left;
    j = mid+1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {   // 오름차순
            temp[k++] = list[i++];
        } else {
            temp[k++] = list[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = list[i++];
    }
    
    while (j <= right) {
        temp[k++] = list[j++];
    }

    for (int l = left; l <= right; ++l) {
        list[l] = temp[l];
    }
}

void mergeSort(int list[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

void printList(int list[]) {
    for (int i = 0; i < 8; ++i) {
        cout << list[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int list[8] = {21, 10, 12, 20, 25, 13, 15, 22};

    // 정렬
    mergeSort(list, 0, 7);

    // 출력
    printList(list);

    return 0;
}