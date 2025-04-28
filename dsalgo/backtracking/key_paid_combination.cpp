#include<iostream>
#include <map>
using namespace std;
/**
Time-complexity:
    L --> max keypaid chars
    N --> input digits size

    O(L^ N) 
    e.g for in L = abc i.e size 3 and input digits = 53 we have 3 ^ 2 calls i.e 9
    also each function call involves a string concatenation that takes O(N) time in the worst case
    Therefore, the total time complexity is O(L^N * N)

Space complexity:
    The total space complexity is the sum of these components:

    Result storage: O(N * L^N) -- > L^N total with each of size N
    Recursion stack: O(N^ 2) 

    Since N × L^N grows much faster than N² for any L > 1, the dominant term is O(N × L^N).
    Therefore, the space complexity is O(N × L^N).

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
