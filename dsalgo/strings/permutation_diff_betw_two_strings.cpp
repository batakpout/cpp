/**
* Example 1: Input: s = "abc", t = "bac",the permutation difference between s and t is equal to |0 - 1| + |1 - 0| + |2 - 2| = 2.
* Example 2:Input: s = "abcde", t = "edbac" Output: 12, permutation difference between s and t is equal to |0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12.


 */

#include<iostream>
using namespace std;

/**
 * Time and space complexity is O(n)
 */
int permutationDiff(string s1, string s2) {
    unordered_map<char, int> m;
    for(int i=0;i<s1.length();i++) {
        m[s1[i]] = i;
    }
    int sum=0;
    for(int i=0;i<s2.length();i++) {
        sum += abs(m[s2[i]] - i);
    }
    return sum;
}

/**
 TC: Outer loop runs n times.For each character s1[i], s2.find(s1[i]) is O(n). So total time: O(n)×O(n)=O(n^2)
 Space Complexity: O(1)
 */
int method2(string s1, string s2) {
    int sum=0;
    for(int i=0;i<s1.length();i++) {
        int i2 = s2.find(s1[i]); //find index of char in s2
        sum += abs(i2 - i);
    }
    return sum;
}

int main() {
    string s1;
    cout << "enter string 1 : ";
    getline(cin, s1);
    string s2;
    cout << "enter string 2 : ";
    getline(cin, s2);
    int result1 = permutationDiff(s1, s2);
    int result2 = method2(s1, s2);
    cout << "Permutation diff1: " << result1 << endl;
    cout << "Permutation 2: " << result2 << endl;
}