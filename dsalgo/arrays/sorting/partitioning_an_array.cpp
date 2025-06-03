#include<iostream>
#include<sstream>
using namespace std;


//SC: O(1), TC: O(N) doesn't place pivot element in correct place for numbers [can be used to separate even/odd, 1's and 0's, 0's and Non zeros]
void partitionEvenOdd(vector<int>& arr) {
    int n = arr.size();
    int i = 0, j = 0;

    while (i < n) {
        if (arr[i] % 2 == 0) {  // check if even
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
}

/**
 * at-last puts pivot at it's correct place.
 * pivot can be at any index p
 * O(N) but does three traversals and uses O(N) extra space
 * stable
 */
void partitionNaive(vector<int> & arr, int l, int h, int p) {
    vector<int> temp(h-l+1);
    int index = 0;
    for(int i=l;i<=h;i++) {
       if(arr[i] < arr[p] && i!=p) {
        temp[index++] = arr[i];
       } 
    }
    temp[index++] = arr[p];
    for(int i=l;i<=h;i++) {
       if(arr[i] > arr[p]) {
        temp[index++] = arr[i];
       } 
    }
    for(int i=l;i<=h;i++) {
        arr[i] = temp[i-l];
    }

}

/*
 *not stable but will put pivot at it's correct place and return its index
 * TC: O(N), single iteration of arr
 * SC: O(1)
 */
int lomutoPartition(vector<int> & arr, int l, int h) {
    //swap(arr[p], arr[h]); // if given pivot at any index make sure pivot element is the last one in lomuto
    int pivot = arr[h];
    int i = l-1;
    for (int j = l;j<=h-1;j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[h]);
    return i+1;

}

/*
 * TC: O(N) SC: O(1)
 * doesn't place pivot at its correct position
 * returns index of last smallest element before greater element
 * it is not stable
 * it has low comparison, works better than lomuto on average
 */
int hoaresPartition(vector<int> & arr, int l, int h) {
    int i = l-1;
    int j = h + 1 ;
    int pivot = arr[l];
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i>=j) return j;
        swap(arr[i], arr[j]);
    }
}

int main() {
    
    vector<int> arr;
    int pivot;
    string line;

    cout << "Enter arr:\n";
    getline(cin, line);

    stringstream ss1(line);
    int temp;
    while (ss1 >> temp) {
        arr.push_back(temp);
    }
    cout << endl;
    cout << "enter pivot index: ";
    cin >> pivot;

    //partitionNaive(arr, 0, arr.size()-1, pivot);
   // int pivotIndex = lomutoPartition(arr, 0, arr.size() - 1);
    int pivotIndex = hoaresPartition(arr, 0, arr.size() - 1);
    cout << "result arr:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "pivot index final: " << pivotIndex;
    return 0;
}