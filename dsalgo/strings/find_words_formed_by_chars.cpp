/**
 * LC, E:  1160 Find Words That Can Be Formed by Characters

* You are given an array of strings words and a string chars. A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).Return the sum of lengths of all good strings in words.
Example 1: Input: words = ["cat","bt","hat","tree", "cac"], chars = "atach" Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6. No "cac" as chars have c only once

Example 2: Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr" Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 
* To form a string using characters from chars, the frequency of each character in chars must be greater than or equal the frequency of that character in the string to be formed.
* whenever we have lower case english letters in context use 26 sized vector
* Time Complexity: O(m + n×k) where:
m = length of chars
n = number of words
k = average length of words

Space Complexity: O(1) - at most 26 characters in vector
 */
#include<iostream>
#include<sstream>
using namespace std;

bool canFormWord(const vector<int>& charCount, string & word) {
    vector<int> wordCount(26,0);
    for(char & ch: word) {
        wordCount[ch - 'a']++;
    }
   
   for(int i=0;i<26;i++) {
    if(wordCount[i] > charCount[i]) return false;
   }
   return true;
}

int countCharacters(vector<string> words, string chars) {
    vector<int> charCount(26, 0);
    for(char & ch: chars) {
        charCount[ch - 'a']++;
    }

    int result = 0;
    for(string & word: words) {
        if(canFormWord(charCount, word))
             result += word.length();
    }
    return result;
}

int main() {
    cout << "enter words array:";
    string line;
    getline(cin, line);
    stringstream sst(line);
    string temp;
    vector<string> words;
    while(sst >> temp) {
        words.push_back(temp);
    }
    cout << endl;
    cout << "enter chars string:";
    string chars;
    getline(cin, chars);
    int result = countCharacters(words, chars);
    cout << "result : " << result << endl;
    return 0;
}
