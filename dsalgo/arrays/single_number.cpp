/**
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
Example 1:Input: nums = [2,2,1] Output: 1
Example 2:Input: nums = [4,1,2,1,2] Output: 4
Example 3: Input: nums = [1] Output: 1

do single number 2, 3 on leetcode
 */

#include<iostream>
#include<sstream>
using namespace std;

//TC: O(N), SC:O(N)
int method1(vector<int> & nums ) {
    int n = nums.size();
    unordered_map<int, int>m;
    for(int item: nums) {
        m[item]++;
    }
    for(int item: nums) {
        if(m[item] == 1) return item;
    }
    return 0;
}
/**
a ^ a = 0 for any integer a, 0 ^ x = x
XOR is commutative and associative, so the order doesn't matter
All paired elements cancel out: 1 ^ 1 = 0, 2 ^ 2 = 0
Remaining: 0 ^ 4 = 4
TC: O(N), SC: O(1)
 */
int usingXOR(vector<int> & nums ) {
    int XOR = 0;
     for(int item: nums) 
        XOR ^= item;
    
    return XOR;
}

int main() {

    string s;
    cout << "enter array: ";
    getline(cin, s);
    stringstream sst(s);
    int temp;

    vector<int> arr;
    while(sst >> temp) {
        arr.push_back(temp);
    }
    int result1 = method1(arr);
    int result2 = usingXOR(arr);
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;
    return 0;
}
