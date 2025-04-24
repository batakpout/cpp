#include<iostream>
using namespace std;

/*
Time Complexity: O(2^n)
Space Complexity: O(n)

# The Tower of Hanoi problem has a recursive solution where:
#   T(n) = 2*T(n-1) + 1
# This results in a binary tree of height `n`, where each level doubles the number of calls.
#
# For n = 3, the recursion_backtracking tree looks like:
#            n=3
#          /     \
#       n=2       n=2
#      /   \     /   \
#    n=1  n=1  n=1  n=1
#   ...  (continues until n=0) --> no of function calls
*/

//move pegs from disk A to B using C
void towerOfHanio(char A, char B, char C, int n) {
    if(n == 0) return;
    else {
        towerOfHanio(A, C, B, n-1);
        cout << "move peg " << n << " from " << A << " -> " << B << endl;
        towerOfHanio(C, B, A, n-1);
    }
}
int main() {

    towerOfHanio('A', 'B', 'C', 3);
    return 0;
}