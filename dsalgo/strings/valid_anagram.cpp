/**
* LE: E: 242. Valid Anagram Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1: Input: s = "anagram", t = "nagaram" Output: true
Example 2: Input: s = "rat", t = "car" Output: false
Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
we will create count arr of size 128 so it can accomodate uni-code characters also
 */

#include <algorithm>
#include<iostream>
using namespace std;
//TC: O(n log n)
bool isAnagram1(string s, string t) {
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    return s == t;
}

//TC: O(N), SC: O(26)
bool isAnagram2(string s, string t) {
    vector<int> count(26, 0);
    for (char & c: s)
        count[c-'a']++;
    for (char & c: t)
        count[c-'a']--;

    bool allZeros =  all_of(begin(count), end(count), [](int i) {
        return i == 0;
    });
    return allZeros;
}

int main() {
    string s, t;
    cout << "Enter s: ";
    cin>>s;
    cout << "Enter t: ";
    cin>>t;
    int res1 = isAnagram1(s, t);
    int res2 = isAnagram2(s, t);
    cout << "res1: " << (res1 == 1 ? "true" : "false") << endl;
    cout << "res2: " << (res2 == 1 ? "true" : "false");
    return 0;
}