#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);

    cout << "Front element: " << q.peek() << endl;
    cout << "Removed element: " << q.pop() << endl;

    if (q.empty()) {
        cout << "Queue is empty";
    } else {
        cout << "Queue is not empty";
    }

    return 0;
}