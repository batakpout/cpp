#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(const string& digits, vector<string>& result, int index, string current) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mp[digits[index]];
        for (char letter : letters) {
            backtrack(digits, result, index + 1, current + letter);
        }
    }
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};
            vector<string> result;
            backtrack(digits, result, 0, "");
            return result;
    }
};

int main() {
    Solution solution;
    
    cout << "enter a digit:\n";
    string digits;
    cin >> digits;
    
    vector<string> result = solution.letterCombinations(digits);
    
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}