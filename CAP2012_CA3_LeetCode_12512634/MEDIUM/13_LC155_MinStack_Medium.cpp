#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << "Minimum: " << s.getMin() << endl;

    s.pop();

    cout << "Top: " << s.top() << endl;
    cout << "Minimum: " << s.getMin() << endl;

    return 0;
}