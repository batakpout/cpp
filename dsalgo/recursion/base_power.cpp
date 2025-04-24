#include<iostream>
using namespace std;
/*
Time-complexity:
The function makes power total recursive calls before reaching the base case (power == 0)
Each call performs:1 multiplication (base * ...), 1 subtraction (power - 1), One comparison (if power == 0).These are constant-time operations (O(1)) per call.
Since there are power recursive calls, the time complexity is O(power)
Space Complexity:
Due to recursion, the space complexity is O(power) because the call stack grows linearly with power.
Example: For power = 5, the call stack holds 5 frames before unwinding.
Comparison with Iterative Version:
The iterative version (iterative(base, power)) also has O(power) time complexity but O(1) space complexity (no call stack overhead).
*/
int basePower(int base, int power) {
    if(power == 0) return 1;
    else return base * basePower(base, power-1);
}

/**
 Time Complexity: Checkout out the screenshot.  we want to find the last term of GP i.e 
 when the algorithm converges to 1, it forms a GP which then after solution lead to Log(power) complexity.
Time-complexity:
The function uses divide-and-conquer (halving power in each recursive call).
The number of recursive calls is O(log₂(power)) because power is divided by 2 each time.
Each call performs:1 division(power // 2),1 or 2 mult (x*x and possibly x * base),1 modulo check (power % 2).
All operations per call are O(1), so total time is O(log power).

Space Complexity: O(log power)
The recursion_backtracking depth is log₂(power) (each call halves power).
Each call adds a stack frame, so space is O(log power).

*/
int basePowerLog(int base, int power) {
    if(power == 0) return 1;
    else {
        int halfOfPowerResult = basePowerLog(base, power / 2);
        int finalResult = halfOfPowerResult * halfOfPowerResult;
        if(power % 2 != 0) finalResult *= base;
        return finalResult;
    }
}

int iterative(int base, int power) {
    int result = 1;
    while (power >= 1) {
        result *= base;
        power -= 1;
    }
    return result;
}

int main() {

    int b, p;
    cout <<  "Enter a base: " << endl;
    cin >> b; 
    cout << endl <<  "Enter a power: " << endl;
    cin >> p;
    int res = basePower(b, p);
    cout << endl << res << endl;
    return 0;
}
