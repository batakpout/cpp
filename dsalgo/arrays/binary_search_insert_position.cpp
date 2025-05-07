 /**
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4

 * must be: O(Log n) time complexity
 */
#include<iostream>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return low;
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

    cout << "Enter item to search:";
    int val;
    cin>>val;

    int res = binarySearch(prices, val);
    cout << "found at index: " << res << endl;
    return 0;
}