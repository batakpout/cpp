#include<iostream>
using namespace std;

/**
 TC: O(n)
 O(1) if delete at the end, O(n) if at the beginning
 --> In array, get and update are O(1)
 */

//hashing have O(1) for insert, get/search, delete O(1) average cases.

int deleteItem(int arr [], int n, int item) {
   int i;
   if(item == arr[n-1]) return n-1;

   for(i=0;i<n;i++) {
     if(arr[i] == item) {
        break;
     }
   }

   if(i == n) return n;

   for(int j = i;j<n-1;j++) {
     arr[j] = arr[j+1];
   }
   return n-1;
}

int main() {
    int size;
    cout << "enter array size:";
    cin >> size;
    int arr[size];
    cout << "enter " << size << " array elements: \n";
    for(int i=0;i<size;i++) {
        cin >> arr[i];
    }

    int item;
    cout << "Enter item to delete: ";
    cin >> item;
    int n = deleteItem(arr, size, item);
    cout << "after deletion array is:\n";
    for(int i=0;i<n;i++) {
        cout <<  arr[i] << " ";
    }
    cout << endl;
}