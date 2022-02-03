// Write a program that implements the following sorting methods to sort a given list ofintegers in ascending
// order iii) Radix sort

#include <bits/stdc++.h>
using namespace std;
void countingSort(int array[], int size, int place) {
    int max = 10;
    int output[size], count[max];
    for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}
void radixsort(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    for (int i = 1; max / i > 0; i *= 10) {
        countingSort(array, n, i);
    }
}
int main() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int array[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    radixsort(array, n);
    cout << "After sorting : ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

// Enter number of elements : 5
// Enter elements : 1 4 8 5 2
// After sorting : 1 2 4 5 8