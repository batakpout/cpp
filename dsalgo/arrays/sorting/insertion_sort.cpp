/**
* Insertion sort is similar to playing cards in our hands. Insert the card in its correct position in a sorted part.
* It works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list.
* O(n^2) in worst case, O(n) when arr is already sorted
* inner loop does 1 checks, next iteration 2 then 3 i.e 1+2+3+..+(n-1) swaps = n * (n-1) / 2 = O(n^2)
* In place and stable 
* used in practise for small array, most compilers use hybrid sort e.g TimSort(uses insertion sort
  for smaller array and merge for larger, IntroSort uses quick+heap sort for large arr and insertion sort for smaller ones)
 */
#include<iostream>
#include<sstream>
using namespace std;

void insertionSort(vector<int> & arr) {
    int curr, prev;
    int n = arr.size();
    for(int i=1;i<n;i++) {
        curr = arr[i];
        prev = i-1;
        while(prev >= 0 && arr[prev] > curr) { // > not >= ensures stable sort
            arr[prev+1]= arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
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

    insertionSort(arr);
    cout << "sorted array:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}