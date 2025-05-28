#include <iostream>
using namespace std;

int main() {
    int a = 5;     // Binary: 0101
    int b = 3;     // Binary: 0011

    int result1 = a ^ b;  // 0101 ^ 0011 = 0110 = 6

    cout << "5 ^ 3 = " << result1 << endl;

    //XOR with same numbers cancels out    
     int c = 7;
    int result2 = c ^ c;  // Always 0
    cout << "7 ^ 7 = " << result2 << endl;

    //XOR with zero returns same value
    int d = 42;
    int result3 = d ^ 0;
    cout << "42 ^ 0 = " << result3 << endl;
    return 0;
}
