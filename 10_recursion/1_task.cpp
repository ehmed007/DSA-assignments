#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 1) {
        return x;
    }
    return power(x,n-1)*x;
}

int arraysum(int array[], int n) {
    if (n == 0) {
        return array[n];
    }
    return arraysum(array, n-1) + array[n];
}

void reversearray(int array[], int start, int end) {
    if (start >= end) {
        return;
    }
    reversearray(array, start + 1, end - 1);
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
}

int main() {
    cout << "value : " << power(2,5) << endl;;
    int array[7] = {1, 2, 4, 7, 14, 0, 34};
    cout << "value : " << arraysum(array,6) << endl;
    reversearray(array, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    return 0;
}