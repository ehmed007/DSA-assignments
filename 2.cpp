#include <iostream>
using namespace std;
 
class Matrix {
    private:
        int* array;
        int rows;
        int cols;
    public:
        Matrix(int rows, int cols) {
            this->rows = rows;
            this->cols = cols;
            this->array = new int[rows * cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    *(array + (i + j * rows)) = 0;
                }
            }
        }
        Matrix(const Matrix& obj) {
            this->rows = obj.rows;
            this->cols = obj.cols;
            this->array = new int[rows * cols];
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    this->set(i,j,*(obj.array + (i + j * rows)));
                }
            }
        }
        Matrix operator=(Matrix &obj) {
            this->rows = obj.rows;
            this->cols = obj.cols;
            this->array = new int[rows * cols];
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    this->set(i,j,*(obj.array + (i + j * rows)));
                }
            }
            return *this;
        }
        
        ~Matrix() {
            delete[] array; 
        }

        int get(int i, int j) {
            if ((i >= 0 && j >= 0) && (i < rows && j < cols)) {
                return *(array + (i + j * rows));
            }
            cout << "\nERROR! indexes are out of bound function will return -1" << endl;
            return -1;
        }

        void set(int i, int j, int v) {
            if ((i >= 0 && j >= 0) && (i < rows && j < cols)) {
                *(array + (i + j * rows)) = v;
                return;
            }
            cout << "\nERROR! indexes are out of bound function" << endl;
        }
        void transpose() {
            Matrix newobj(*this);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    this->set(j,i,*(newobj.array + (i + j * rows)));
                }
            }
        }
        void print() {
            cout << "\nMATRIX : " << endl;
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    cout << this->get(i, j) << " ";
                }
                cout << endl;
            }
        }
        void printSubMatrix(int r1, int r2, int c1, int c2) {
            if ((r1 >= 0 && r2 < this->rows) && (c1 >= 0 && c2 < this->cols)) {
                cout << "\nSUB MATRIX : " << endl;
                for (int i = r1; i <= r2; i++) {
                    for (int j = c1; j <= c2; j++) {
                        cout << this->get(i, j) << " ";
                    }
                    cout << endl;
                }
                return;
            }
            cout << "\nERROR! indexes are out of bound function" << endl;
        }
        void makeEmpty(int n) {
            if (n < this->rows && n < this->cols) {
                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= n; j++) {
                        this->set(i, j, 0);
                    }
                }
                return;
            }
            cout << "\nERROR! index N is out of bound function" << endl;
        }
        void add(Matrix first, Matrix second) {
            if (first.rows == second.rows && first.cols == second.cols) {
                this->rows = first.rows;
                this->cols = first.cols;
                this->array = new int[rows * cols];
                for (int i = 0; i < this->rows; i++) {
                    for (int j = 0; j < this->cols; j++) {
                        this->set(i,j,(*(first.array + (i + j * rows)) + (*(second.array + (i + j * rows)))));
                    }
                }
                return;   
            }
            cout << "ERROR! First and Second has not same dimensions..." << endl;
        }
        void enter_value() {
            int v;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << "enter value : ";
                    cin >> v;
                    set(i, j, v);
                }
            }
        }
};



int main() {
    Matrix obj(3,3);
    obj.enter_value();
    Matrix obj1(obj);
    obj.add(obj,obj1);
    obj.print();
    int i,j;
    while(1) {
        cout << "enter i value : ";
        cin >> i;
        cout << "enter j value : ";
        cin >> j;
        cout << "\nthis -> "<< obj.get(i,j);
        cout << endl;
    }
}



    