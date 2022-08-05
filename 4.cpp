#include "iostream"
using namespace std;

int intersection1(int arr1[], int arr2[], int arr3[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[count++] = arr1[i];
            }
        }
    }
    return count;
}


int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int intersection2(int arr1[], int arr2[], int arr3[], int size) {
    for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]){
				int temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
    int count = 0;
    int check;
    for (int i = 0; i < size; i++) {
    check = binarySearch(arr2,0,size-1,arr1[i]);
        if (check != -1) {
            arr3[count++] = arr1[i];
        }
    }
    return count;
}

int main() {
    int arr1[] = {1,4,6,3,7,20,5,47,96,36};
    int arr2[] = {3,36,2,26,4,7,5,47,100,13};
    // int arr1[] = {1,4,6,3,7,20};
    // int arr2[] = {3,36,2,26,4,67};
    
    int arr3[10];
    int size = intersection1(arr1,arr2,arr3,10);
    for (int i = 0; i < size; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}