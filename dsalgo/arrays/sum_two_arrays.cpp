#include<iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/**
Complexity	Value
Time	O(max(n1, n2))
Space	O(max(n1, n2))
 */
void sumTwoLists(const vector<int>& nums1, const vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();
    int n3 = max(n1, n2);
    vector<int> nums3(n3, 0);
    int c = 0, i = n1-1, j=n2-1,k=n3-1, d;
    while(k>=0) {
        d = c;
        if(i >=0) d += nums1[i];
        if(j >=0) d += nums2[j];
        c = d/10;
        d = d%10;
        nums3[k] = d;
        i--;
        j--;
        k--;
    }
    if (c > 0) cout << c << " ";
    
    for (int val : nums3) {
        cout << val << " ";
    }

    cout << endl;
}
int main() {
    vector<int> a1, a2;
    string line;

    cout << "Enter first list (space-separated digits): ";
    getline(cin, line);// Read an entire line of input (until Enter is pressed) into the 'line' string

    stringstream ss1(line);// Create a stringstream from the input line
    int temp;
    while (ss1 >> temp) { // Extract numbers from the stringstream one by one
        a1.push_back(temp);
    }

    cout << "Enter second list (space-separated digits): ";
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> temp) {
        a2.push_back(temp);
    }

    sumTwoLists(a1, a2);
    return 0;
}
/**
 A stringstream is a class that allows you to treat a string as a stream, similar to how cin lets you stream input from the console. It allows you to read from a string as if it were an input stream, using the same extraction operators (>>) that you use with cin.
 */