/**
 * a string num representing a large integer. An integer is good if it meets the following conditions:
    It is a substring of num with length 3 and it consists of only one unique digit.

 * Return the maximum good integer as a string or an empty string "" if no such integer exists.
Example 1: Input: num = "6777133339" Output: "777"ˀExplanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2: Input: num = "2300019" Output: "000" Explanation: "000" is the only good integer.
Example 3: Input: num = "42352338" Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.

Constraint: 3 <= num.length <= 1000

Time complexity: O(n)
Space complexity: O(1)
 */
#include<iostream>
using namespace std;

string largestGoodInteger(string num) {
    int n = num.length();
    char maxChar= ' ';
    for(int i=2;i<n;i++) {
        if(num[i] == num[i-1] && num[i] == num[i-2]) maxChar = max(maxChar, num[i]);
    }
    if(maxChar == ' ') return "";

    return string(3, maxChar);        
}

int main() {
    string num ;
    cout << "enter string:" << endl;;
    cin >> num;
    string res = largestGoodInteger(num);
    cout << "result : " << res << endl;
    return 0;
}