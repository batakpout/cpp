#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
TC: O(n)
SC: O(1)
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

    int arr[] = {4,0,2,1,3};
   rearrangeArray(arr, 5);
  for(int i=0;i<5;i++) {
    cout << arr[i] << " ";
  }
    return 0;
}