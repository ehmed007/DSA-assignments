#include <iostream>
#include "fstream"
#include "string"
using namespace std;

char is_lower(char a) {
	if (a <= 97) {
		a = a + 32;
	}
	return a;
}

int check_occurrance(string str1, string str2) {
	int count = 0;
	int check = 0;
	for (int i = 0; i < str1.length(); i++) {
		if(is_lower(str2[0]) == is_lower(str1[i])) {
			for (int j = 0; j < str2.length(); j++) {
				if (is_lower(str2[j]) == is_lower(str1[i + j])) {
					check++;
				} 
			}
			if (check == str2.length()) {
				count++;
			}
			check = 0;
		}
	}
	return count;
}

int findkthSmallest(int array[], int size, int k) {
	int kth_smallest = -1;
	if (k >= size) {
		cout << "\n<<error>> 'K is out of bound '" << endl;
	}
	for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] != array[i+1]) {
			count++;
		}
		if (count == k) {
			kth_smallest = array[i];
		}
	}
	return kth_smallest;
}

int main() {

	//int array[] = {3,2,5,8,9,2,4,10,2,36,37};
	//cout << findkthSmallest(array,10,5);

    fstream newfile;
    newfile.open("input3.txt",ios::in);
    string first_line;
    getline(newfile,first_line); 
    int count = 0;
	string line;
    while (!newfile.eof()) {
        getline(newfile,line); 
        cout << "LINE " << count+1 << " : " << check_occurrance(line,first_line) << endl;
        count++;
    }
    return 0;
}