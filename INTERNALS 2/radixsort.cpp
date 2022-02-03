// radix sort
#include <bits/stdc++.h>
using namespace std;
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixsort(int arr[], int n) {
    int a = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > a) {
            a = arr[i];
        }
    }
    for (int exp = 1; a / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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
    radixsort(arr, n);
    cout << "After sorting : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
