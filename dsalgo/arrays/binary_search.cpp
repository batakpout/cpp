#include<iostream>
using namespace std;

int binarySearchIterative(int arr [], int n, int target) {
    int low =0, high=n-1;
    while(low<=high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid > target]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int binarySearchRecursive(int arr [], int low, int high, int target) {
    if(high >= low) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) return binarySearchRecursive(arr, low, mid-1, target);
        return binarySearchRecursive(arr, mid+1, high, target);
    }
    return -1;
}

/**
 in build binary search functions
 */

void inbuildBinarySearchFunctions() {
    vector<int> vec = {10, 15, 20, 25, 30, 35};
    if(binary_search(vec.begin(), vec.end(), 15)) 
        cout << "15 exists in vector\n";
    else 
        cout << "15 does not exist\n";
  
    int arr [] = {10, 15, 20, 25, 30, 35};
    int n = sizeof(arr) / sizeof(int);
    if(binary_search(arr, arr+n, 20))
        cout << "20 exists in vector\n";
    else 
        cout << "20 does not exist\n";
}

void upperBound() {

  /**
   *  lower_bound: >= value
      upper_bound: > value
   * upper_bound: Returns an iterator pointing to the first element in the range [begin, end) that is greater than (>) the given value.
   * :: (scope resolution operator) tells the compiler to look inside the vector<int> type for the definition of iterator.
   * upper1, it's like printing a memory address (or an iterator position), which isn’t useful on its own.
   * *upper1 is the dereference operator in C++. It is used to access the value that the iterator upper1 points to.
   * Subtracting two iterators from the same container gives you the distance between them, i.e., an integer representing how many  steps upper1 is from v.begin()
   */
    vector<int>v{10,20,30,40,50};
    cout << "Vector contains :"; 
    for (int i = 0; i < v.size(); i++) 
        cout << " " << v[i]; 
    cout << "\n"; 

    vector<int>:: iterator upper1, upper2, upper3; //
    upper1 = upper_bound(v.begin(), v.end(), 35);
    upper2 = upper_bound(v.begin(), v.end(), 40);
    upper3 = upper_bound(v.begin(), v.end(), 60); // returns end iterator

    cout << "upper bound of 35: " << *upper1 << endl;
    cout << "upper bound of 40: " << *upper2 << endl;
    if(upper3 != v.end()) cout << "upper3: " << *upper3 << endl; // else segmentation fault without if check
    cout << "\nUpper_bound for element 35 is at position : " << (upper1 - v.begin()); 
    cout << "\nUpper_bound for element 40 is at position : " << (upper2 - v.begin())<<"\n";
    cout << "\nUpper_bound for element 60 is at position : " << (upper3 - v.begin())<<"\n";
    //for arr: int up1 = upper_bound(arr, arr+n, 35) - arr; gives index of upper bound of 35

}
/**
 Returns an iterator pointing to the first element in the range [begin, end) that is not less than (>=) the given value.
 */

void lowerBound() {
 vector<int>v{10,20,30,40,50};
    cout << "Vector contains :"; 
    for (int i = 0; i < v.size(); i++) 
        cout << " " << v[i]; 
    cout << "\n"; 

    vector<int>:: iterator lower1, lower2, lower3, lower4; //
    lower1 = lower_bound(v.begin(), v.end(), 35); // output 40
    lower2 = lower_bound(v.begin(), v.end(), 40);//output 40
    lower3 = lower_bound(v.begin(), v.end(), 10); // returns 10
    lower4 = lower_bound(v.begin(), v.end(), 60); //for 60 gives end iterator

    cout << "lower bound of 35: " << *lower1 << endl;
    cout << "lower bound of 40: " << *lower2 << endl;
    cout << "lower bound of 10: " << *lower3 << endl;
    if(lower4 != v.end()) cout << "lower4: " << *lower3 << endl; // else segmentation fault without if check
    cout << "\nLower_bound for element 35 is at position : " << (lower1 - v.begin()); 
    cout << "\nLower_bound for element 40 is at position : " << (lower2 - v.begin())<<"\n";
    cout << "\nLower_bound for element 60 is at position : " << (lower4 - v.begin())<<"\n";
    //for arr: int lw1 = lower_bound(arr, arr+n, 35) - arr; gives index of lower bound
}

int main() {
    inbuildBinarySearchFunctions();
    upperBound();
    cout << "--separator--" << endl;
    lowerBound();
    return 0;
}