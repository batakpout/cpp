#include<iostream>
#include<map>
#include<unordered_set>
#include<vector>

using namespace std;

/**
  TC: O(n)
  Auxillary space: O(n)
 * used in leet-code
 ->  unordered_map uses a hash table to store its elements.
 ->  map uses a self-balancing binary search tree (usually a Red-Black Tree)
 -> map has O(Log n) complexity for insert, lookup, delete,
 -> so used unordered_map, it has O(1) average case, O(n) worst case, so we say O(1)
 */
 
pair<int, int> usingMaps(const vector<int> & nums, int target) {
    unordered_map<int, int> map;
    int n = nums.size();
    for(int i=0;i<n;i++) {
        if(map.find(nums[i]) != map.end()) return {map[nums[i]], i};
        map[target - nums[i]] = i;

    }
    return {-1, -1};
}

int binarySearch(int arr [], int low, int high, int target) {
   int mid;
   while(low <= high) {
     mid = low + (high - low) / 2;
     if(arr[mid] == target) return mid;
     else if(arr[mid] > target) high = mid-1;
     else low = mid + 1;
   }
   return -1;
}

/**
  In C++, when you add an integer to a pointer, the result is a pointer that is offset by the size of the data type the pointer points to.
  For example, if arr is a pointer to an int (and int is 4 bytes), then arr + 1 points to the next int in memory, which is 4 bytes away from arr
  {2,3,1,4,6,5}
  arr points to address 100 (first element)
  arr + 6 points to address 124 (just after the last element).
  sort(arr, arr+ n), It sorts the elements in the range [100, 124), which corresponds to the 6 elements of the array.
 */
/**
  TC: sort-> O(n log n), binary search -> O(Log N), arr traverse -> O(n) 
  so, binary search + traverse -> O(N Log N)
  total: O(n log n) + O(N log N)
  AS: O(1)
 */
pair<int, int> usingBinarySearch(int arr [], int n, int target) {
    sort(arr, arr + n);

    for(int i=0;i<n;i++) {
        int result = binarySearch(arr, i+1, n - 1, target-arr[i]);
        if(result != -1) return {i, result};
    }
    return {-1, -1};
}

/**
TC: O(n²), for using two nested loops
AS: O(1)
*/
pair<int, int> twoSumUsingArrays(int arr[], int n, int target) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i] + arr[j] == target) {
                return {i, j};
            }
         }
    }
    return {-1, -1};
}

/**
 TC: sort -> O(N Log N), no traverse complexity becoz we don't traverse whole array
 AS: O(1)
 This approach is the best approach for a sorted array. But if array is not sorted, then we use hashing.
 */
pair<int, int> usingTwoPointers(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int sum = arr[left] + arr[right];
        if(sum == target) return {left, right};
        else if(sum > target) right = right - 1;
        else left = left + 1;
    }
    return {-1, -1};
}

/**
  unordered_set is essentially a hashset. It stores elements in hashtable.
  It allows for O(1) for lookups, insertions and deletions.

  TC: O(n)
  AS: O(n)
 */
bool usingHashing(int arr[], int n, int target) {
    unordered_set<int> set;
    for(int i=0;i<n;i++) {
        if(set.find(target - arr[i]) != set.end()) return true;
        set.insert(arr[i]);
    }
    return false;
}

int main() {
   
    int arr[7];
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "enter 7 array elements: " << endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout << "enter target element: " << endl;
    int target;
    cin>>target;

    //pair<int, int> result = twoSumUsingArrays(arr,n ,target);
   // pair<int, int> result = usingMap(arr,n ,target);
    pair<int, int> result = usingMaps(vector<int>{1,2,3,4,5,6,9} ,target);
   // pair<int, int> result = usingBinarySearch(arr,n ,target);
    //pair<int, int> result = usingTwoPointers(arr,n ,target);
    if(result.first != -1) {
        cout << "Indices: " << result.first << ", " << result.second << endl;
    } else {
        cout << "Not two sum solution found: " << result.first << ", " <<result.second << endl;
    }
    return 0;
}
