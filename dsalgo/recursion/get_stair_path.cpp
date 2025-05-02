/**
 *comming down from stairs with 1 or 2 or 3 steps
 * find optimized solutions here: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
 Time complexity:
 * at each level you branch into 3 recursive calls (n-1, n-2, and n-3). This branching creates a ternary recursion tree:At level 0: 1 call At level 1: 3 calls At level 2: 3² calls
At level n: 3ⁿ calls
Thus, the total number of recursive calls is O(3ⁿ). Also O(n) for each string concatenation operation so
O(3ⁿ * n)
We also insert each string into a vector<string>, which is amortized constant time per insertion, so doesn’t change the asymptotic upper bound.

Space Complexity:
Number of strings: O(3ⁿ), Length of each string: O(n)
Total memory used to store the result vector = O(n × 3ⁿ)
O(n × 3ⁿ) — dominated by the size of the output (the number and length of all possible paths)
Plus O(n) for the call stack, but that's negligible in comparison.
 */

#include<iostream>
using namespace std;

vector<string> findStairPaths(int n) {

    if(n == 0) {
        vector<string> v;
        v.push_back("");
        return v;
    }
    if(n < 0) {
        vector<string> v;
        return v;
    }
    vector<string> path1 = findStairPaths(n-1);
    vector<string> path2 = findStairPaths(n-2);
    vector<string> path3 = findStairPaths(n-3);

    vector<string> result;
    for(string c: path1) {
        result.push_back("1" + c);
    }
    for(string c: path2) {
        result.push_back("2" + c);
    }
    for(string c: path3) {
        result.push_back("3" + c);
    }
    return result;

}

int main() {
    cout << "Enter number of stairs: ";
    int s;
    cin >> s;
    vector<string> result = findStairPaths(s);
    cout << "Ways to come down " << s << " stairs with 1 or 2 or 3 steps\n";
    for(const auto &s: result) {
        cout << s << endl;
    }
    cout << endl;
    return 0;
}