#include "iostream"
using namespace std;

template <class T>
class Queue {
    private:
        T *data; 
        int rear; 
        int front; 
        const int MAX_SIZE; 
    public:
    Queue(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE) {
        this->front = -1;
        this->rear = -1;
        this->data = new T[MAX_SIZE];
    }
    ~Queue() {
        delete[] data;
    }
    void enQueue(const T newItem) {
        if (!isFull()) {
            if (front == -1) {
                front++;
            }
            rear = (rear+1) % MAX_SIZE;
            data[rear] = newItem;
        }
        else {
            cerr << "\nQueue is FULL" << endl;
        }
    } 
    void deQueue() {
        if (!isEmpty()) {
            if (rear == front) {
                rear = -1;
                front = -1;
            }
            else {
                front = (front+1) % MAX_SIZE;
            }
        }
        else {
            cerr << "\n Queue is EMPTY" << endl;
        }
    }
    void clear() {
        this->front = -1;
        this->rear = -1;
        cout << "Queue is CLEARED!" << endl;
    } 
    T getFront() const {
        if (!isEmpty()) {
            return data[front];
        }
        else {
            cerr << "\nQueue is EMTPY" << endl;
            return -1;
        }
    }
    T getRear() const {
        if (!isEmpty()) {
            return data[rear];
        }
        else {
            cerr << "\n Queue is EMTPY" << endl;
            return -1;
        }
    } 
    bool isEmpty() const {
        if (rear == -1 && front == -1) {
            return true;
        }
        return false;
    }
    bool isFull() const {
        if ((rear + 1) % MAX_SIZE == front) {
            return true;
        }
        return false;
    } 
    void showStructure() const {
        if (!isEmpty()) {
            cout << endl;
            int i = front;
            cout << "front---->     ";
            while(i != rear) {
                cout << data[i] << endl;
                cout << "               ";
                i = (i+1) % MAX_SIZE;
            }
            cout << data[i];
            cout << "     <----rear" << endl;
            cout << endl;    
        } 
        else {
            cerr << "\nQueue is empty" << endl;
        }
    }
    void check() {
        cout << "\nfront : " << front << endl;
        cout << "rear : " << rear << endl;
    }
};

int main() {
    Queue <float> queue(6);
    queue.enQueue(5.0);
    queue.enQueue(6.5);
    queue.showStructure();
    queue.deQueue();
    queue.enQueue(-3.0);
    queue.enQueue(-8.0);
    queue.showStructure();

    queue.deQueue();    
    queue.deQueue();    
    queue.deQueue();
    queue.showStructure();
    return 0;   
}