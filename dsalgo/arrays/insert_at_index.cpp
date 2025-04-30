#include<iostream>
using namespace std;

/*
 insert item at a particular index and return size of the array
 TC: O(n) :
  O(n): inserting at the begining
  O(1) inserting at the end

  for dynamic collection, if collection if full, it will first create a new one with
  double the size , then copy all elements from old to new, delete the old and then
  insert item at the end, so O(n) for dynamic collection insert at the end when collection 
  is full but on average when collection if not full it is O(1) for inserts at end, so on 
  average it is O(1).So these dynamic collections mostly pre-allocate more memory to ensure amortized 
  complexity. this is equivalent to push_back method in vectors.
*/
int insertAtIndex(int arr [], int n, int pos, int capacity, int item) {
    if(n == capacity) return n;
    int idx = pos - 1;
    for(int i = n-1;i>=idx;i--) {
        arr[i + 1] = arr[i];
    }
    arr[idx] = item;
    return n + 1;
}

int main() {
     // undefined behavior, which causes the [zsh: abort.] error , reason: arr[i+1] = arr[i] but arr[i+1] is out of bounds. //so size should be dynamic
    const int capacity = 10;    
    int arr[capacity] = {1, 2, 3, 4, 5}; // Initialize with some values
    int n = 5;
    int res1 = insertAtIndex(arr, n, 2, 5, 7); //as capacity = n so return just n
    cout << "res1: " << res1 << endl;

    for(int i = 0; i < n;i++) {
        cout << arr[i];
        if(i != n-1) {
            cout << ",";
        }
    }
    cout << endl;
    n = insertAtIndex(arr, n, 2, 10, 8);
    cout << "res2: " << n << endl;
    cout << endl;
     for(int i = 0; i < n;i++) {
        cout << arr[i];
        if(i != n-1) {
            cout << ",";
        }
    }
    cout << endl;
}