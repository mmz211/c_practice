#include <iostream>
#include <vector>


using namespace std;

class Queue {

    public:
        Queue(int n=10): arr(n), head(0), tail(0) {


        }

        void push(int x) {

            if (full()) {
                cout << "full" << endl;
            }
            arr[tail] = x;
            tail += 1;
            return;

        }

        void pop() {

            if (empty()) {
                return;
            }

            head += 1;
        }

        bool empty() {
            return head == tail;
        }
        bool full() {

            return tail == arr.size();
        }

        int front() {

            return arr[head];
        }

        int size() {

            return tail - head;
        }

        void output() {

            cout << "Queue" << endl;
            for (int i = head; i < tail; i++ ) {
                cout << arr[i] << " ";
            }

            cout << endl;

        }

    private:

        int head, tail;
        int cnt;
        vector<int> arr;
};



int main() {

    string op;

    int value;

    Queue q(5);

    while (cin >> op) {

        if (op == "insert") {

            cin >> value;
            q.push(value);

        } else if (op == "front") {

            cout << "front : " << q.front() << endl;

        } else if (op == "pop") {

            q.pop();

        } else if (op == "push") {

            cout << "size" << q.size() << endl;

        } else if (op == "exit") {
            break;
        }

        q.output();
    }

    return 0;
}
