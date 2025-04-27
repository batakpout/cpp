#include<iostream>

using namespace std;

/**
 --> time complexity is exponential, 2 to power n

 The left branch (from friendsPairing(n-1)) reduces n by 1.

The right branch (from friendsPairing(n-2)) reduces n by 2 but is multiplied by (n−1)
The only difference is the extra O(1) work per call i.e multiplication by (n-1).

Space complexity: O(n) due to the recursion stack.

 */
int friendsPairing(int n) {
    if(n<=2) {
        return n;
    }

    //return ((n-2) * friendsPairing(n - 2)) + (friendsPairing(n-1) + friendsPairing(n-2));
    return friendsPairing(n-1) + friendsPairing(n-2) * (n-1);
}
int main() {

    cout << "enter friends count:\n";
    int n;
    cin >> n;
    int res = friendsPairing(n);
    cout << "total combos:\n";
    cout << res << endl;
    return 0;
}