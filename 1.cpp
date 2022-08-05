#include <iostream>
using namespace std;

struct Point3D {
    float x, y, z;
};

class PointList {
    private:
        struct Point3D* array;
        int maxSize;
        int curSize;
        int cursor;
    public:
        // constructor
        PointList(int maxSize) {
            this->maxSize = maxSize;
            this->cursor = -1;
            this->curSize = -1;
            this->array = new Point3D[this->maxSize];
            for (int i = 0; i < this->maxSize; i++) {
                this->array[i].x = 0;
                this->array[i].y = 0;
                this->array[i].z = 0;
            }
        }
        // destructor
        ~PointList() {
            delete[] this->array;
        }
        // Methods
        void insert(struct Point3D newPoint) {
            if (!this->is_full()) {
                cursor++;
                curSize++;
                array[curSize] = newPoint;
            } 
            else {
                cout << "\nLIST IS FULL" << endl;
            }
        }
        bool is_empty() {
            if (this->curSize == -1) {
                return true;
            }
            return false;
        }
        bool is_full() {
            if (this->curSize == this->maxSize) {
                return true;
            }
            return false;
        }
        void showStructure() {
            if (!this->is_empty()) {
                for (int i = 0; i <= this->curSize; i++) {
                    cout << "\nPoint " << i << " :\n";
                    cout << "x = " << this->array[i].x << endl;
                    cout << "y = " << this->array[i].y << endl;
                    cout << "z = " << this->array[i].z << endl;
                    cout << endl << endl;
                }
            } else {
                cout << "\nLIST IS EMPTY" << endl;
            }
        }
        Point3D getCursor() {
            if (!this->is_empty()) {
                return array[cursor];
            } 
            else {
                cout << "\nLIST IS EMPTY" << endl;
                struct Point3D newPoint;
                newPoint.x = -1;
                newPoint.y = -1;
                newPoint.z = -1;
                return newPoint;
            }
        }
        void gotoBeginnning() {
            if (!this->is_empty()) {
                cursor = 0;
            }
            else {
                cout << "\nLIST IS EMPTY" << endl;
            }
        }
        void gotoEnd() {
            if (!this->is_empty()) {
                cursor = curSize;
            }
            else {
                cout << "\nLIST IS EMPTY" << endl;
            }
        }
        bool gotoNext() {
            if (cursor == curSize) {
                return false;
            } else {
                cursor++;
                return true;
            }
        }
        bool gotoPrior() {
            if (cursor == -1) {
                return false;
            } else {
                cursor--;
                return true;
            }
        }
        void clear() {
            this->curSize = -1;
            this->cursor = -1;
            for (int i = 0; i < this->maxSize; i++) {
                this->array[i].x = 0;
                this->array[i].y = 0;
                this->array[i].z = 0;
            }
        }
        bool replace(struct Point3D newPoint) {
            if (!this->is_empty()) {
                struct Point3D temp = newPoint;
                newPoint = this->array[this->cursor];
                this->array[this->cursor] = temp;
                return true;
            } 
            return false;
        }
        void remove() {
            if (!this->is_empty()) {
                this->array[cursor].x = 0;
                this->array[cursor].y = 0;
                this->array[cursor].z = 0;
                cursor--;
                if (!this->is_empty()) {
                    if (cursor == curSize) {
                        cursor = 0;
                    }
                }
            }
        }
};

int main() {
    PointList list(5);
    list.showStructure();
    struct Point3D one;
    one.x = 2;
    one.y = 3;
    one.z = 7;
    list.insert(one);
    cout << endl;
    cout << list.getCursor().x;
    cout << endl;
    cout << list.getCursor().y;
    cout << endl;
    cout << list.getCursor().z;
    cout << endl;
    list.showStructure();
}