#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> units = {"", "One", "Two", "Three", "Four", "Five", 
                                "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                            "Sixty", "Seventy", "Eighty", "Ninety"};
   vector<string> scales = {"", " Thousand", " Million", " Billion", " Trillion"};
    string convertLessThanOneThousand(int n) {
        string res;
        if(n>=100) {
        res = units[n/100] + " Hundred";
        n %= 100;
        if(n > 0) res += " ";
        }
    
        if(n>=20) {
            res += tens[n/10];
            n %= 10;
            if(n>0) {
            res += " " + units[n]; 
            }
        } else if(n >= 10) {
            res += teens[n - 10];
        } else if(n > 0) {
            res += units[n];
        }

        return res;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";

        string result;
        result.reserve(200);

        int scaleIndex = 0;
        while(num > 0) {
            int c = num%1000;
            if(c != 0) {
                string chunkWords = convertLessThanOneThousand(c);
                 if (!result.empty()) {
                chunkWords += scales[scaleIndex] + " " + result;
                } else {
                chunkWords += scales[scaleIndex];
                } 
            result = chunkWords;
            }
            scaleIndex++;
            num = num / 1000;
        }   
        return result;
    }
};

int main() {
    int  n;
    cout << "Enter a number";
    cin >> n;
    
    Solution solution;
    string result = solution.numberToWords(n);
    
    cout << "Result:\n";
    cout << result<< endl;
    cout << endl;
    
    return 0;
}
