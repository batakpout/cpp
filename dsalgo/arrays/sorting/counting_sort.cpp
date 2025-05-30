/**
*   works on data that is in the range e.g student marks [0 to 100], 
*   It can be a stable algorithm, try later from PEP?
*   Counting sort can also work for negative numbers. You just have to rebase the current range of numbers.
    e.g, if you have the range [-23, 54] we will rebase every number at number+min(Range) i.e number+23.
    So your range for the original code will become [-23+23,54+23] or [0,77]. 
    Now after applying the algorithm just replace every number in the sorted array by number-23.
*   Advantage of Counting Sort:
        It has a time complexity of O(n + k) 
        When the range of input values (k) is relatively small compared to the number of elements (n), 
         counting sort can be more efficient than merge and quick sort because it doesn't rely on comparisons between elements.
        It is easy to code.
*   Disadvantage of Counting Sort:
        It doesn’t work on decimal values.
        It is inefficient if the range of values to be sorted is very large.
        It is not an in-place sorting algorithm, uses extra space for sorting the array elements.
*   TC: O(range + N), range is max number in arr and create an array till range, N is size of the array
 */
#include<iostream>
#include<sstream>
using namespace std;

void countSort(vector<int> & arr) {

    int largest = -1;
    for(int num: arr) {
        largest = max(largest, num);
    }

    vector<int> freq(largest+1, 0);
     for(int num: arr) {
        freq[num]++;
    }

    int j=0;
    for(int i=0;i<=largest;i++) {
        while(freq[i] > 0) {
           arr[j] = i;
           freq[i]--;
           j++; 
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

    countSort(arr);
    cout << "sorted array:\n";
    for(int i=0;i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}