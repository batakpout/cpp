#include<iostream>
using namespace std;

/**
Each call performs:A constant-time multiplication (n * ...), A constant-time subtraction (n - 1),A comparison (if n == 1).
Since the work per call is O(1), and there are n calls, the total time complexity is O(n).

Each recursive call adds a new stack frame, consuming memory.
The maximum depth of the call stack is n (e.g., factorial(5) uses 5 stack frames).
Hence, space complexity is O(n) (due to recursion_backtracking).

 */
int factorial(int num) {
    if(num == 0) return 1; // num == 0 must be it otherwise it will fail for num = 0 else we will get segmentation fault if num == 1
    else return num * factorial(num -1);
}

int main() {

    int n;
    cout <<  "Enter a number: " << endl;
    cin >> n;
    int res = factorial(n);
    cout << endl << res << endl;
    return 0;
}
