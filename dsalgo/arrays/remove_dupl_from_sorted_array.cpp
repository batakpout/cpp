/**
 * Remove duplicates from sorted array
 * input sorted array
 * return the number of unique elements in nums.
 * O(n) time complexity
 * Two Pointer technique
 * Input: nums = [0,0,1,1,1,2,2,3,3,4]
   Output: 5, nums = [0,1,2,3,4,_,_,_,_,_] and total = 5
 */
#include<iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        int n = nums.size();
        for (int j = 1; j < n; ++j) {
            if (nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }

int main() {
    int size;
    cout << "enter array size:";
    cin >> size;
    vector<int>prices(size);
    cout << "enter " << size << " array elements: \n";
    for(int i=0;i<size;i++) {
        cin >> prices[i];
    }

    int res = removeDuplicates(prices);
    cout << "total unique items in array: " << res << endl;
    return 0;
}