#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
arrT[i] becomes arr[arr[i]].

TC: O(n)
SC: O(1)
Each number is between 0 and n-1 (inclusive), meaning they're all valid indices.
You want to rearrange the array, such that each element at index i becomes arr[arr[i]].

The Core Trick (Packing Two Numbers in One)

arr = {3, 2, 0, 1}, n = 4
after step-1 array becomes--> arr = {7, 2, 12, 9}
Each number now holds:
Old value: arr[i] % 4
New value: arr[i] / 4
Step 2: Extract the new value
Now just divide all by n:
*/
void rearrangeArray(int arr [], int n) {

    for(int i =0 ;i<n;i++) {
        arr[i] = arr[i] + (arr[arr[i]] % n) * n;
    }
    for(int i=0;i<n;i++) {
        arr[i] = arr[i] / n;
    }

}



int main() {

    int arr[] = {3,2,0,1};
   rearrangeArray(arr, 4);
  for(int i=0;i<4;i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
    return 0;
}
