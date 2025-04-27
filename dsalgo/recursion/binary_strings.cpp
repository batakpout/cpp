#include<iostream>
#include <cmath>

using namespace std;

int totalNoOfBinaryStrings(int n) {

    if(n<2) return n + 1;
    return totalNoOfBinaryStrings(n-1) + totalNoOfBinaryStrings(n-2);

}

vector<string> result;

void helper(string str, int n, int i) {
    if(i == n) {
        result.push_back(str);
        return;
    }

    string s1 = str;
    s1.push_back('0');
    helper(s1, n, i + 1);
    if(i > 0 && str[i-1] == '0') {
        str.push_back('1');
        // Here you don't use str after the recursive call returns hence no s1 used here
        helper(str, n, i + 1); 
    } else if(i == 0) {
         str.push_back('1');
        // Here you don't use str after the recursive call returns hence no s1 used here
        helper(str, n, i + 1);
    }


}

vector<string> binaryStrings(int n){
     result.clear();
     string str;//default constructor creates empty string
     helper(str,n,0);
     return result;

}


int main() {

    cout << "enter no: ";
    int n;
    cin >> n;
    cout << endl << "Result: " << totalNoOfBinaryStrings(n) << endl;
    cout << "Binary String without consecutive 1's: " << endl;
    vector<string> v = binaryStrings(n);
    for(auto item: v) {
        cout << item << endl;
    }
    return 0;
}