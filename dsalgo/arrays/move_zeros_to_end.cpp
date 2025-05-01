 /**
 * Remove item val from  array
 * Two Pointer technique
 * return the number of remaining elements in nums without val.
 * O(n) time complexity
 */
#include<iostream>
using namespace std;

//O()
void moveToZeroNaive(int nums [], int n) {
      for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                for(int j=i+1;j<n;j++) {
                    if(nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        i++;
                    }
                }
            }
        }
}
//O(N)
void moveZerosToEnd(int nums [], int n) {
      int nonZeroPos = 0;
      for(int i=0;i<n;i++) {
        if(nums[i] != 0) {
            swap(nums[nonZeroPos++], nums[i]);
        }
      }
}

int main() {
    int size;
    cout << "enter array size:";
    cin >> size;
    int arr[size];
    cout << "enter " << size << " array elements: \n";
    for(int i=0;i<size;i++) {
        cin >> arr[i];
    }

    cout << "Entered array:";
    for(int i=0;i<size;i++) {
        cout <<  arr[i] << " ";
    }
    cout << endl << "array after moving zeros to end:\n";
    moveZerosToEnd(arr, size);
    //moveToZeroNaive(arr, size);
     for(int i=0;i<size;i++) {
        cout <<  arr[i] << " ";
    }
    cout << endl;
    return 0;
}