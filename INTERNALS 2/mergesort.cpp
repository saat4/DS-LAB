#include <bits/stdc++.h>
using namespace std;
void merge(int *array, int a, int b, int c) {
    int i, j, k, na, nc;
    na = b - a + 1;
    nc = c - b;
    int aarr[na], carr[nc];
    for (i = 0; i < na; i++)
        aarr[i] = array[a + i];
    for (j = 0; j < nc; j++)
        carr[j] = array[b + 1 + j];
    i = 0;
    j = 0;
    k = a;
    while (i < na && j < nc) {
        if (aarr[i] <= carr[j]) {
            array[k] = aarr[i];
            i++;
        } else {
            array[k] = carr[j];
            j++;
        }
        k++;
    }
    while (i < na) {
        array[k] = aarr[i];
        i++;
        k++;
    }
    while (j < nc) {
        array[k] = carr[j];
        j++;
        k++;
    }
}
void mergeSort(int *array, int a, int c) {
    if (a < c) {
        int b = a + (c - a) / 2;
        mergeSort(array, a, b);
        mergeSort(array, b + 1, c);
        merge(array, a, b, c);
    }
}
int main() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Array after Sorting : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}