#include<iostream>
#include<unordered_set>
using namespace std;
/**
 * e.g Input: nums = [2, 4, 6, 9, 15, 16, 18], target = 15
 Output: [2,3]
 */

/**
TC: O(n²), for using two nested loops
AS: O(1)
*/
pair<int, int> twoSumUsingArrays(int arr [], int n, int target) {

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]+ arr[j] == target) {
               return {i, j};
            } 
        }
    }
     return {-1, -1}; 
}

int binarySearch(int arr[], int left, int right, int target) {
  
    while(left <= right) {
        int mid = left + (right-left) / 2;
        if(arr[mid] == target) return true;
        if(arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

/**
  TC: sort-> O(n log n), binary search -> O(Log N), arr traverse -> O(n) 
  so, binary search + traverse -> O(N Log N)
  total: O(N log N) + O(N log N)
  AS: O(1)
 */
bool twoSumUsingBinarySearch(int arr [], int n, int target) {
    
     sort(arr, arr + n);
     for(int i=0;i<n;i++) {

        int complement = target - arr[i];
        if(binarySearch(arr, i + 1, n, complement)) return true;
     }
     return false;
}

/**
 TC: sort -> O(N Log N), no traverse complexity becoz we don't traverse whole array
 AS: O(1)
 This approach is the best approach for a sorted array. But if array is not sorted, then we use hashing.
 */

bool twoSumUsingTwoPointers(int arr [], int n, int target) {
    
     sort(arr, arr + n);
     int left = 0, right = n - 1;
     while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) return true;
        else if(sum > target) right--;
        else left++;
     }
     return false;
}

/**
 ->  unordered_map uses a hash table to store its elements.
 ->  map uses a self-balancing binary search tree (usually a Red-Black Tree)
 -> map has O(Log n) complexity for insert, lookup, delete,
 -> so used unordered_map, it has O(1) average case, O(n) worst case, so we say O(1)

  TC: O(n)
  AS: O(n)
 */

vector<int> twoSumUsingMap(vector<int> & nums, int target) {
    unordered_map<int, int> map;
    int n = nums.size();
    for(int i=0;n;i++) {
        int complement = target - nums[i];
        if(map.find(complement) != map.end()) return {map[complement], i};
        map[nums[i]] = i;
    }
    return {};
}

/**
  unordered_set is essentially a hashset. It stores elements in hashtable.
  It allows for O(1) for lookups, insertions and deletions.

  TC: O(n)
  AS: O(n)
 */
bool twoSumUsingHashing(int arr [], int n, int target) {
   
    unordered_set<int> set; 
    for(int i=0;i<n;i++) {
        if(set.find(target-arr[i]) != set.end()) return true;
        
        set.insert(arr[i]);
    }

    return false;
   
}
