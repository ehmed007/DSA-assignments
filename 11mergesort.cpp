#include "iostream"
using namespace std;

void mergeSort(int a[], int size1, int b[], int size2) {
    int mergedArray[size1+size2];
    int i = 0, j = 0;
    int c = 0;
    while (i != size1 && j != size2) {
        if (a[i] <= b[j]) {
            mergedArray[c++] = a[i++];
        }
        if (a[i] > b[j]) {
            mergedArray[c++] = b[j++];
        }
    }
    for (int i = 0; i < size1+size2; i++) {
        cout << mergedArray[i] << " ";
    }
}

int main() {
    int a1[] = {1, 2, 5};
    int a2[] = {3, 4, 7};
    mergeSort(a1, 3, a2, 3);
    return 0;
}