#include<iostream>
using namespace std;

//1 2 3 4 5 6
// O(end-start+1) or O(N)
int naive(int arr[], int start, int end) {
    int res = 0;
    for(int i = start;i<=end;i++) {
        res += arr[i];
    }
    return res;
}

void buildPrefixSumArray(int arr[], int n) {
    for(int i=1;i<n;i++) {
        arr[i] = arr[i] + arr[i-1];
    }
}

//O(1)
int prefixSum(int arr[], int start, int end) {
    if(start == 0) return  arr[end];
    return arr[end] - arr[start - 1];
}

int main() {
  //,6,7,8,9,10,11,12,13,14
    int arr [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int n = sizeof(arr) / sizeof(int);
    cout << "size of arr: " << n << endl;
    int res1 = naive(arr, 2, 9);
    buildPrefixSumArray(arr, n);
    cout << endl;
    int res2 = prefixSum(arr, 2, 9);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}