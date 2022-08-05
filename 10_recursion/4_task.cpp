#include "iostream"
using namespace std;

bool traverse(int array[], int i, int j, int k) {
    if (i == j) {
        return false;
    }
    else if (array[i] + array[j] == k) {
        return true;
    }
    traverse(array, i, j - 1, k);
}

bool checksum(int array[], int start, int end, int k) {
    if (start == end) {
        return false;
    }
    else if (traverse(array, start, end, k) == 1) {
        return true;
    }
    checksum(array, start + 1, end, k);
}             

int main() {   
    int array[7] = {1, 2, 4, 7, 14, 0, 34};
    cout << checksum(array,0,4,100);
    return 0;   
}               