/**
* Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
  Each letter in magazine can only be used once in ransomNote.
  Example 1: Input: ransomNote = "a", magazine = "b" Output: false
  Example 2: Input: ransomNote = "aa", magazine = "ab" Output: false
  Example 3: Input: ransomNote = "aa", magazine = "aab" Output: true

 Time Complexity:
    First loop (over magazine):
    Each character of magazine is visited once:
    → O(m), where m is the length of magazine.
    Second loop (over ransomNote):
    Each character of ransomNote is visited once:
    → O(n), where n is the length of ransomNote.
    Total Time Complexity: O(m + n)

Space Complexity:
    A vector<int> charCount(26) is used to count characters (assuming only lowercase English letters)
    O(1) (constant space, since 26 is fixed and independent of input size)
 */
#include<iostream>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> charCount(26, 0);
    for(char & ch: magazine)
        charCount[ch - 'a']++;

    for(char & ch: ransomNote) {
        if(charCount[ch-'a'] == 0) return false;
        charCount[ch - 'a']--; 
    }    
    return true;
}

int main() {
    string ransomNote, magazine ;
    cout << "enter magazine:" << endl;;
    cin >> magazine;
    cout << "enter ranson note: " << endl;
    cin >> ransomNote;
    int res = canConstruct(ransomNote, magazine);
    cout << "result : " << (res > 0 ? "true" : "false") << endl;
    return 0;
}