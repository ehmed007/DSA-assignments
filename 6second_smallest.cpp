#include "iostream"
using namespace std;

void secondsmallest(int array[], int size) {
    int first_smallest = array[0];
    int second_smallest = array[1];
    for (int i = 0; i < size; i++) {
        if (first_smallest > array[i]) {
            second_smallest = first_smallest;
            first_smallest = array[i];
        }
        if (second_smallest > array[i] && array[i] != first_smallest) {
            second_smallest = array[i];
        }
    }
    cout << "first  : " << first_smallest << endl;
    cout << "second : " << second_smallest << endl;
}

int main() {
    int array[] = {3,6,7,-8,9,0,5,1,27,3,-6,8,8,2};
    int size = sizeof(array)/sizeof(int);
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    secondsmallest(array,size);
    
    return 0;
}