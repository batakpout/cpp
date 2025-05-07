 /**
  * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 * O(n) time complexity
 *  Two Pointer technique
 * Input: nums = [3,2,2,3], val = 3
   Output: 2, nums = [2,2,_,_]
 */
#include<iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();
        for (int i = 0;i<n; ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
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

    cout << "Enter item to remove:";
    int val;
    cin>>val;

    int res = removeElement(prices, val);
    cout << "item in array after removal of duplicate item: " << res << endl;
    return 0;
}