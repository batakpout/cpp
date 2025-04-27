#include<iostream>
#include <cmath>

using namespace std;

int totalNoOfBinaryStrings(int n) {

    if(n<2) return n + 1;
    return totalNoOfBinaryStrings(n-1) + totalNoOfBinaryStrings(n-2);

}

/**
time-complexity: 
 * O(2^n) time complexity in the worst case. However, due to the constraint (where '1' can only follow '0'  or be at position 0), the actual number of strings generated will be less than 2^n.
 * using memoisation in dp this can be reduced to linear complexity.
 * using matrix exponentiation [CP] for linear recurrence i.e f(n) = f(n-1) + f(n-2), we can solve linear recurrence in logrithmic time, so using
 matrix exponentiation we can reduce it down to O((k*k*k) Log N), k is no of terms on which this
 N is depending i.e for 2 to power n, k is 2 so O(8 * LogN) --> uses matrices in maths

Space Complexity:
*Recursion stack depth: O(n) since the recursion goes n levels deep.
The total space complexity is O(n) for the recursion stack plus O(n) for the string storage at each level, which simplifies to O(n).

*Note that the overall space used by the final result array (storing all valid strings) would be O(k*n) where k is the number of valid strings generated, but this is separate from the recursive function's own space complexity.
 */

vector<string> result;

void helper(string str, int n, int i) {
    if(i == n) {
        result.push_back(str);
        return;
    }

    string s1 = str;
    s1.push_back('0');
    helper(s1, n, i + 1);
    if(i > 0 && str[i-1] == '0') {
        str.push_back('1');
        // Here you don't use str after the recursive call returns hence no s1 used here
        helper(str, n, i + 1); 
    } else if(i == 0) {
         str.push_back('1');
        // Here you don't use str after the recursive call returns hence no s1 used here
        helper(str, n, i + 1);
    }


}

vector<string> binaryStrings(int n){
     result.clear();
     string str;//default constructor creates empty string
     helper(str,n,0);
     return result;

}


int main() {

    cout << "enter no: ";
    int n;
    cin >> n;
    cout << endl << "Result: " << totalNoOfBinaryStrings(n) << endl;
    cout << "Binary String without consecutive 1's: " << endl;
    vector<string> v = binaryStrings(n);
    for(auto item: v) {
        cout << item << endl;
    }
    return 0;
}