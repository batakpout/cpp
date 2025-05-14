#include <iostream>
using namespace std;

/**
Time-complexity:
Recursive Fibonacci with O(2^n) time complexity.
    Total function calls grow exponentially:
    - 1 call for fib(n)
    - 2 calls for fib(n-1)+fib(n-2)
    - 4 calls at next level
    - Forms a geometric progression (GP) ~ 2^n total calls
 */
int fibo(int n) { // n>=0
    if (n == 0 || n == 1) {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

void print_fibo_series(int n) {
    for (int i = 0; i <= n; i++) {
        cout << fibo(i) << " ";
    }
    cout << endl;
}

int main() {
    // Example usage
    cout << "Fibonacci series up to 5: ";
    print_fibo_series(5);  // Output: 0 1 1 2 3 5
    
    cout << "Fibonacci series up to 8: ";
    print_fibo_series(8);  // Output: 0 1 1 2 3 5 8 13 21
    
    return 0;
}
