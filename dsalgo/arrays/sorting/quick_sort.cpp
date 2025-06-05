/**
 * Divide and conquer algorithm
 * worst case time complexity: O(n^2) [when the array is sorted in any direction both lomut and hoares lead to worst complexity]
 * Despite O(n^2) worst case, it is considereed faster, because of following reasons:
    - In-place [but requires auxillary space for recursion call stack not for dividing array]
    - Due to in-place, it is cache friendly.
    - it is tail recursive
    - Average case: O(n log n)
* Partition is key function(naive[if we want stable quick sort], lomuto, hoares)
* if we don't need stablility then quick sort or its variation like Introsort is faster than merge sort else
  if we need stablility then merge sort is preferred.

🚀 Why Quicksort Performs Better in Practice
Reason	                        Explanation
In-place sorting	            Quicksort doesn’t require extra space (except for the recursion stack), while merge sort uses O(n) additional space.
Better cache performance	    Quicksort works with contiguous memory and benefits from CPU caching due to good spatial locality.
Low constant factors	        The overhead in merge sort (copying to/from temp arrays) makes it slower despite better worst-case bounds.
Tail recursion optimization	    Modern compilers can optimize tail-recursive quicksort variants, making them more memory efficient.

❌ But Merge Sort Has Advantages Too
Merge Sort Strength	        Benefit
Stable sort	                    Maintains the relative order of equal elements — useful in many applications (e.g., sorting records by name and then age).
Consistent time complexity	    Always O(n log n), even in worst case.
Better for linked lists	        Merge sort works better for linked lists because it does not require array copying or random access — both of which are inefficient for linked lists.

Space complexity:
worst case: O(n)
best case: O(log(n))

to ensure we don't run into worse case, we randomize the picking of pivot:
 - p = random(l, h)
 - swap(arr[l], arr[p]) for hoares
 - or swap(arr[h], arr[p]) for lomutos

 quick sort is good for sorting binary array[partition algorithm places element on side]
 */
#include<iostream>
#include<sstream>
using namespace std;

int lomutoPartition(vector<int> & arr, int l, int h) {
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

void quickSortLomuto(vector<int> & arr, int l, int h) {
    if (l<h) {
        int pI = lomutoPartition(arr, l, h);
        quickSortLomuto(arr, l, pI-1);
        quickSortLomuto(arr, pI+1, h);
    }
}

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

void quickSortHoares(vector<int> & arr, int l, int h) {
    if (l<h) {
        int pI = hoaresPartition(arr, l, h);
        quickSortLomuto(arr, l, pI);
        quickSortLomuto(arr, pI+1, h);
    }
}

void quickSortHoaresTailOpt(vector<int> & arr, int l, int h) { Begin:
    if (l<h) {
        int pI = hoaresPartition(arr, l, h);
        /**
         * tail call optimization to avoid extra space usage.
         * check which part has more elements and then call tail call opt. on larger part
         */
        quickSortLomuto(arr, l, pI);
        l = pI+1;
        goto Begin;
    }
}

int main() {
    vector<int> arr;
    string line;

    cout << "Enter arr to quick sort:\n";
    getline(cin, line);

    stringstream ss1(line);
    int temp;
    while (ss1 >> temp) {
        arr.push_back(temp);
    }

    //quickSortLomuto(arr, 0 , arr.size() - 1);
    quickSortHoaresTailOpt(arr, 0 , arr.size() - 1);
    cout << "sorted array:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}