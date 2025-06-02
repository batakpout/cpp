/**
 * Divide and conquer algorithm(divide, conquer and merge), it is stable algorithm (maintains original order of equal elements)
 * O(n log n) time complexity on a single processor for a random input, takes O(n) extra space, so not an in-place sorting algorithm.
   (some variants e.g blocked merge sort used constant space)
 * for arrays, in general, quick sort works better than the merge sort
 * most libraries e.g java 8, python uses merge sort or tim-sort(merge+insertion sort)
 */
#include<iostream>
#include<sstream>
using namespace std;

vector<int> merge1(const vector<int> & a, const vector<int> & b) {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<int> merge;
    while(i<n and j<m) {
        if(a[i] <= b[j]) { //<= makes it stable
            merge.push_back(a[i]);
            i++;
        } else {
            merge.push_back(b[j]);
            j++;
        }
    }
    while(i<n) 
        merge.push_back(a[i++]);
    
    while(j<m) 
        merge.push_back(b[j++]);
    
    return merge;

}

void merge2(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < temp.size(); ++i) {
        arr[low + i] = temp[i];
    }
}

vector<int> mergeSort1(vector<int> arr, int low, int high) {
    if(low == high) {
        return vector<int>{arr[low]};
    }
    int mid = low + (high-low)/2;
    vector<int> fsh = mergeSort1(arr, low, mid);
    vector<int> ssh = mergeSort1(arr, mid+1, high);
    return merge1(fsh, ssh);
}

void mergeSort2(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort2(arr, low, mid);
    mergeSort2(arr, mid + 1, high);
    merge2(arr, low, mid, high);
}

int main() {
    vector<int> arr;
    string line;

    cout << "Enter arr to merge sort:\n";
    getline(cin, line);

    stringstream ss1(line);
    int temp;
    while (ss1 >> temp) {
        arr.push_back(temp);
    }

    mergeSort2(arr, 0 , arr.size() - 1);
    cout << "sorted array:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}