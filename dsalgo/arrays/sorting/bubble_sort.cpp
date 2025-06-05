/**
 * comparison-based like selection sort, but they differ in how they sort elements. Bubble Sort swaps adjacent elements,
    so the largest unsorted element "bubbles up" to its correct position. while Selection Sort minimizes swaps by selecting the right element in each pass.
 *  O(n^2) ,  inner j loop runs maximum no of time so it runs: (n−1)+(n−2)+⋯+2+1= [n * (n−1)/2]
 * Best: O(n)[if the array is already sorted else ] Average: O(n^2) Worst: O(n^2)
 * in-place and stable sorting algorithm
 * comparison-based sorting algoriths limit the efficiency of algorithms in certain cases
 * cocktail sort is better version of bubble sort, it traverses from both the sides
 */
#include<iostream>
#include<sstream>
using namespace std;

bool compareFunction(int a, int b) {
    return a > b; //arr[j] > arr[j+1] else a<b does the opposite
}
void bubbleSort(vector<int> & arr) {
    int n = arr.size();
    bool swapped;
    for(int i=0;i<n-1;i++) {
        swapped = false;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j + 1]) {
             //  if(compareFunction(arr[j], arr[j+1])) {
            //    cout << "swapping happens" << endl;
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(!swapped) break;
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

    bubbleSort(arr);
    cout << "sorted array:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}