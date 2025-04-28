#include<iostream>
#include <map>
using namespace std;
/**
Time-complexity:
    L --> max keypaid chars
    N --> input digits size

    O(L^ N) 
    e.g for in L = abc i.e size 3 and input digits = 53 we have 3 ^ 2 calls i.e 9
    can be O(L ^ N)

Space complexity:
    Recursion Stack:
        The maximum depth of recursion is N (length of digits).
        We need to store all possible combinations. As calculated above, there can be up to 4^n combinations.

        So, the space complexity is O(4^n + n) which simplifies to O(4^n) since 4^n grows much faster than n.


 */
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

vector<string> keyPaidCombinations2(const string & digits) {
   if (digits.empty()) return {};
    vector<string> result;
    backtrack(digits, result, 0, "");
    return result;
}

int main() {
    string s;
    cin >> s;
    vector<string> v= keyPaidCombinations2(s);
    for (const string& str : v) {
        cout << str << endl;
    }
    return 0;
}