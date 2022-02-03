#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int *arr, int first, int last) {
    int p, temp, i, j;
    if (first < last) {
        int pivot = i = first, j = last;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last) i++;
            while (arr[j] > arr[pivot]) j--;
            if (i < j) {
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[pivot], &arr[j]);
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "Sorted elements are : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}