#include <iostream>
using namespace std;

int main() {
    
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 3;

    for (int j = 0; j < k; j++) {
 
        int last = nums[n - 1];

        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
    }

    // Array print karo
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}