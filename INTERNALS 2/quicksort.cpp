#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int arr[10], int first, int last) {
    int pivot, temp, i, j;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last) i++;
            while (arr[j] > arr[pivot]) j--;
            if (i < j) swap(&arr[i], &arr[j]);
        }
        swap(&arr[pivot], &arr[j]);
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}
int main() {
    int arr[20], n, i;
    cout << "Enter the no of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "Sorted elements are : ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}