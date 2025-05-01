/**
 * Remove duplicates from sorted array
 * input sorted array
 * return the number of unique elements in nums.
 * O(n) time complexity
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