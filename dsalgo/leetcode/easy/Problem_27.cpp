 /**
 * Remove item val from  array
 * return the number of remaining elements in nums without val.
 * O(n) time complexity
 */
#include<iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
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