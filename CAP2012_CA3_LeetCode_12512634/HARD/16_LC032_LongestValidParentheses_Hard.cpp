#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {

    stack<int> st;
    st.push(-1);

    int answer = 0;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            }
            else {
                answer = max(answer, i - st.top());
            }
        }
    }

    return answer;
}

int main() {

    string s = ")()())";

    cout << "Longest valid parentheses length: ";
    cout << longestValidParentheses(s);

    return 0;
}