/**
  - key idea: repeatedly find the minimum element from the
    unsorted part and putting it at the begining.
  - O(n^2) in all the cases.
  - inner j loop runs: (n−1)+(n−2)+⋯+2+1= [n * (n−1)​]/2
  - Does less memory writes compared to quick, merge, insertion sort etc
    but cycle-sort is optimal in terms of memory writes.
    e.g in EEP ROM, writes are expensive
  - The selection sort never makes more than O(N) swaps and can be useful when memory writing is costly.
  - gives basic idea for heap sort, it's just that heap sort uses heap DS to optimize selection sort.
  - in-place [it does not require extra memory for sorting]
  - Simple and easy to understand, Works well with small datasets.  
  => it is not stable [means the order of same elements change when we sort]  
     e.g[90,12,34,55,90,2] now in first iteration 90 swaps with 2 and come to the end,even though its position was before the other 90, now it will remain after that 90 so it changed the order of the same element, hence it is no stable sort.   
  =>   Does not work well on large datasets.
 */
#include<iostream>
#include <sstream>
using namespace std;

void selectionSort(vector<int> &arr) {
    int minIndex;
    int n = arr.size();
    for(int i=0;i<n-1;i++) {
        minIndex = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;    
        }
        if(minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}
/*
 - stable selection sort
 - replacing swaps with shifts
 - TC: O(n^2) also performs shifts, which take O(n) in the worst case, so O(n^2) + O(n)
*/
void stableSelectionSort(vector<int> & arr) {
    int minIndex;
    int n = arr.size();
    for(int i=0;i<n-1;i++) {
        minIndex = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        if(minIndex != i) {
            int minValue = arr[minIndex];
            for(int k=minIndex;k>i;k--) {
                arr[k] = arr[k-1];
            }
            arr[i] = minValue;
        }
    }
}

int main() {
    vector<int> arr;
    string line;

    cout << "Enter arr to sort:\n";
    getline(cin, line);

    stringstream ss1(line);
    int temp;
    while (ss1 >> temp) {
        arr.push_back(temp);
    }

    selectionSort(arr);
    cout << "sorted array:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
