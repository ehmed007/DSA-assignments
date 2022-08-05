#include <iostream>
using namespace std;


template <class T>
class Stack {
    private:
        //Data members
        T *data; //array of items to be allocated dynamically as per MAX_SIZE
        int top; //top of the stack
        const int MAX_SIZE = 5;; //maximum capacity of the stack
        int min;
    public:
        //constructor
        Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE) {
            this->data = new T[this->MAX_SIZE];
            this->top = -1;
        }

        //destructor
        ~Stack() {
            delete[] data;
        }

        //stack manipulation operations
        void Push(const T newItem) { //push a new item
            if (!isFull()) {
                this->top++;
                this->data[this->top] = newItem;
                return;
            }
            cerr << "\n<<error>> stack is full";
        }

        void Pop() {
            if (!isEmpty()) {
                this->top--;
                return;
            }
            cout << "\n<<error>> stack is empty!";
        } //pop an item

        void clear() {
            this->top = -1;
            cout << "\nstack is cleared";
        } //clear the stack

        //stack accessor
        T getTop() const {
            if (!isEmpty()) {
                return top;
            }
            cout << "<<stack>> is empty";
        }
        int getMIN() {
            if (!isEmpty()) {
                return min;
            }
            cout << "\nStack is empty" << endl;
            return -1;
        }
        //return item at the top
        //stack status operations
        bool isEmpty() const {
            if (this->top == -1) {
                return true;
            }
            return false;
        } //is stack empty?

        bool isFull() const {
            if (this->top == this->MAX_SIZE-1) {
                return true;
            }
            return false;
        } //is stack full?
        //outputs the data in stack. If the stack is empty, outputs “Empty Stack”.

        void showStructure() const {
            if (isEmpty()) {
                cout << "\n<<error>> stack is empty!";
                return;
            }
            cout << endl;
            cout << "TOP----->      ";
            for (int i = top; i > -1; i--) {
                cout << this->data[i] << endl;
                cout << "               ";
            }
        }
};

int main() {
    Stack <float>stack;
    stack.Push(5.0);
    stack.Push(6.5);
    stack.showStructure();
    stack.Push(-3.0);
    stack.Push(-8.0);
    stack.showStructure();
    stack.Pop();
    stack.Pop();
    stack.showStructure();
    return 0;
}