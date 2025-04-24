#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
  also called as string subsequences
  * Total Subsets Generated: For a string of length n, there are 2ⁿ subsets     (including the empty subset)
  * The total work done is O(n · 2ⁿ) (since each of the 2ⁿ subsets is constructed in O(n) time due to string concatenation
  Time Complexity = O(n · 2ⁿ)

* Space Complexity:
    Recursion Stack Depth:
    The recursion goes n levels deep (one call per character).
    Stack space = O(n) (due to recursion).

    Output Storage:
    The method stores 2ⁿ subsets, each of max length n.
    Total space for subsets = O(n · 2ⁿ).

*/
vector<string> subsets(string str) {
    
    if(str.size() == 0) {
       vector<string> bres;  
       bres.push_back("");
       return bres;
    }

    char ch = str[0];
    string ros = str.substr(1);
    vector<string> rres = subsets(ros);
    vector<string> mres;

    for(string rstr: rres) {
        mres.push_back("" + rstr);
        mres.push_back(ch + rstr);
    }
    return mres;

}

int main() {

    string str;
    cout << "Enter a string:" << endl;
    cin >> str;
    vector<string> res = subsets(str);
    
    cout << "[";
    for(int i=0;i<res.size();i++) {
        cout << res[i];
        if(i != res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}