#include <iostream>
using namespace std;

class Collection {
    private:
        int *data;
        int size;        
    public:
        Collection(int size) {
            this->size = size;
            data = new int[size];

            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        }

        Collection(int array[], int size) {
            this->size = size;
            data = new int[size];

            for (int i = 0; i < size; i++) {
                if(array[i] > 0) {
                    data[i] = array[i];
                }
                else {
                    data[i] = 0;
                } 
            }
        }

        Collection(const Collection &obj) {
            size = obj.size;
            data = new int[size];

            for (int i = 0; i < size; i++) {
                if(obj.data[i] > 0) {
                    data[i] = obj.data[i];
                }
                else {
                    data[i] = 0;
                }
            }
        }

        ~Collection() {
            delete[] data;
        }


        int getSize() {
            return size;
        }

        void printCollection() {
            cout << "Data: ";
            for (int i = 0; i < size; i++) {
                cout <<  data[i] << " ";
            }
            cout << endl;
        }

        void getCollection() {
            int d = 0;
            for (int i = 0; i < size; i++) {
                cout << "Enter Data[" << i << "]: ";
                cin >> d;
                if(d > 0) {
                    data[i] = d;
                }
                else {
                    data[i] = 0;
                }
            }
        }

        void insertElement(int k, int i) {
            if(i < size && i >= 0) {
                if(k >= 0) {
                    data[i] = k;
                } 
                else {
                    cout << "**ERROR** The passed integer is negative! So, it cannot be inserts." << endl;
                } 
            } else {
                cout << "**ERROR** The passed index doesnot exist in array size!" << endl;
            }
        }

        bool findElement(int key) {
            for (int i = 0; i < size; i++) {
                if(key == data[i]) {
                    return true;
                }
            }
            return false;
        }

        Collection operator=(const Collection &obj) {
            if(this != &obj) {
                if(size != obj.size) {
                    delete[] data;
                    size = obj.size;

                    data = new int[size];
                }
                for (int i = 0; i < size; i++) {
                    data[i] = obj.data[i];
                }
            }
            return *this;
        }

        Collection operator+(const Collection &obj) const {
            Collection temp(0);
            if(obj.size == size) {
                temp.size = size;

                for (int i = 0; i < size; i++) {
                    temp.data[i] = obj.data[i] + data[i];
                }
            } else {
                cout << "ERROR!!!...Sizes are not equal" << endl;
                temp.size = -1;
                temp.data = NULL;
            }

            return temp;
        }

        bool operator==(const Collection &obj) const {
            if(size != obj.size) {
                return false;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if(data[i] != obj.data[i]) return false;
                }
            }
            return true;
        }
};


int main() {
    int arr[6] = {1, -2, -3, 4, 35, 6};
    Collection obj0(5), obj1(arr, 6), obj2(obj1), obj3(5);
    Collection obj4 = (obj0 + obj3);

    obj1.printCollection();
    obj4.printCollection();
    return 0;
}