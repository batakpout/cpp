#include<iostream>
using namespace std;

vector<string> units = {"", "One", "Two", "Three", "Four", "Five", 
                             "Six", "Seven", "Eight", "Nine"};
vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                           "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> scales = {"", " Thousand", " Million", " Billion", " Trillion"};

//Runs in O(1) time (fixed operations, no loops dependent on input size).
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
   // "One  Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
   // "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
}

/**
Processes the number in groups of 3 digits.
Maximum number of chunks = 4 (since INT_MAX = 2,147,483,647 has 10 digits → ceil(10/3) = 4 chunks).
For each chunk, it calls convertLessThanOneThousand() (O(1) and does concatenation (O(1) per chunk).
Total Time Complexity = O(1) (since the number of chunks is constant for 32-bit integers).

Predefined Arrays (units, teens, tens, scales):
Occupy O(1) space (fixed-size lookup tables)
Output String (result):

Maximum length of the English words for INT_MAX is ~200 characters (e.g., "Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven").
Space Complexity = O(1) (bounded by fixed maximum output size).
 */
string numberToWords(int num) {
    if(num == 0) return "Zero";

    string result;
    // Reserve space based on expected output size to avoid reallocations
    result.reserve(200);

    int scaleIndex = 0;
     while(num > 0) {
        int c = num%1000;
        if(c != 0) {
            string chunkWords = convertLessThanOneThousand(c);
              if (!result.empty()) {
                chunkWords += scales[scaleIndex] + " " + result; //still puts extra space e.g 99999
                // Ninety Nine  Thousand Nine Hundred Ninety Nine extra space b/w Nine and Thousand , ignore for now                      
            } else {
                chunkWords += scales[scaleIndex]; // cases like 123 no spaces at last as scaleIndex  = 0 and from vector we get "", 1000 and scaleIndex > 0, so space before " thousand" in vector
            }
            result = chunkWords;
        }
        scaleIndex++;
        num = num / 1000;
     }   
     return result;
}

int main() {

    cout << "enter a no:\n";
    int n;
    cin >> n;
    string res = numberToWords(n);
    cout << endl << res;
    return 0;
}