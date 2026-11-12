#include <iostream>
using namespace std;

int main() {
    int nums[] = {1, 1, 2};
    int n = 3;

    int k = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    cout << k << endl;

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}