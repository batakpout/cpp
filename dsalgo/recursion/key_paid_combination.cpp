#include<iostream>
#include<map>

using namespace std;
     map<char, string> mp = {
        {'0', ""},
        {'1', "abc"},
        {'2', "def"},
        {'3', "ghi"},
        {'4', "jkl"},
        {'5', "mnop"},
        {'6', "qrst"},
        {'7', "uv"},
        {'8', "wxyz"}
    };
vector<string> keyPaidCombinations(string digits) {
    if (digits.empty()) return {};
    if(digits.size() == 1) {
        string keypadChars = mp[digits[0]];
        vector<string> result;
        for (char c : keypadChars) {
            singleCharList.push_back(string(1, c)); // create a string from one character
        }      
        return singleCharList;
    }
    
    char firstDigit = digits[0];
    string restDigits = digits.substr(1);
    vector<string> combinations = keyPaidCombinations(restDigits);
    string currentChars = mp[digits[0]];
    vector<string> resultList;
    for (char c : currentChars) {            
        for (const string& str : combinations) { 
            resultList.push_back(string(1, c) + str);
        }
    }
    return resultList;

}
int main() {

    vector<string> r = keyPaidCombinations("573");
    for(const string & s : r) {
        cout << s << endl;
    }

    return 0;
}