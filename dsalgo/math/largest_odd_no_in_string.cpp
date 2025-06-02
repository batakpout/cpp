/**
 * LC: M: 1903. Largest Odd Number in String

 You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
Example 1: Input: num = "52" Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

Example 2:Input: num = "4206" Output: ""
Explanation: There are no odd numbers in "4206".

Example 3: Input: num = "35427" Output: "35427"
Explanation: "35427" is already an odd number.

This solution for it is called a greedy solution because it makes a locally optimal choice at each step without considering all possible alternatives, and this local optimization leads to the globally optimal solution.

A non-greedy approach might generate all possible substrings, check which ones are odd, and then find the maximum - much more complex and unnecessary.
 */

#include<iostream>
using namespace std;

/**Approach - Simple Greedy
T.C : O(n)
S.C : O(1)
So it's greedy because it picks the first valid solution that maximizes what we want — the largest odd-valued substring — without backtracking or considering alternatives.
*/
 string largestOddNumber(string num) {

    int n = num.size();
    for(int i=n-1;i>=0;i--) {
      if((num[i] - '0')%2 != 0)
       return num.substr(0, i+1);
    }
    return "";       
}

int main() {
    cout << "enter a string num: ";
    string num;
    cin >> num;
    string res = largestOddNumber(num);
    cout << "largest int: " << res << endl;

}