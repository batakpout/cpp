/**
* LC: E: 1422. Maximum Score After Splitting a String
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty
substrings (i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the
right substring.
Example 1: Input: s = "011101" Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111" Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3: Input: s = "1111" Output: 3

Constraints:
2 <= s.length <= 500
The string s consists of characters '0' and '1' only.
 */
#include<iostream>
using namespace std;

//O(N^2) but constraint is just 500 so avoids TLE
int maxScoreBruteForce(string s) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int zeros_count = 0;
        for (int j = 0; j <= i; j++) {
            if (s[j] == '0')
                zeros_count++;
        }
        int one_count = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] == '1')
                one_count++;
        }
        res = max(res, zeros_count + one_count);
    }
    return res;
}

//O(N) but two passes of string
int maxScoreTwoPasses(string s) {
    int n = s.size();
    int totalOnes = count(begin(s), end(s), '1');
    int leftOnes = 0, zeros = 0, rightOnes = 0;
    int res = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') zeros++; // or totalOnes++; here and we can skip rightOnes = totalOnes - leftOnes;
        else leftOnes++;
        rightOnes = totalOnes - leftOnes;
        res = max(res, zeros + rightOnes);
    }
    return res;
}

//O(N) (1 Pass - Use equation)
/**
  no of 1's = 1 (left) + 1(right)
  no of 0's = Z(left) + Z(right)
  score = max of Z(left) + 1(right)
  1(right) = total_ones - 1(left)
  so,
  score = Z(left) + total_one - 1(left)
  or score = max(Z(left) -1(left)) + total_ones
 */
int maxScoreSinglePass(string s) {
    int n = s.size();
    int score = INT_MIN;
    int zeros = 0, ones = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1') ones++;
        else zeros++;
        score = max(score, zeros - ones);
    }
    if (s[n-1] == '1') ones++;
    return ones + score; //now onesLeft will have all 1's
    return 1;
}

int main() {
    cout << "enter binary string:";
    string str;
    getline(cin, str);
    int res1 = maxScoreBruteForce(str);
    int res2 = maxScoreTwoPasses(str);
    int res3 = maxScoreSinglePass(str);
    cout << "res1: " << res1;
    cout << "res2: " << res2;
    cout << "res3: " << res3;
    return 0;
}
