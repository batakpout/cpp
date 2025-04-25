#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
TC: O(n)
SC: O(n)
*/
void reverseUsingTempArray(int arr [], int n) {

  int reversed[n];
  
  for(int i=0;i<n;i++) {
    reversed[i] = arr[n - i - 1];
  }

}

/* Best way
TC: O(n)
SC: O(1)  (in-place reversal)
*/
void reverseUsingTwoPointer(int arr [], int n) {
    int left = 0;
    int right = n - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

/*
TC: O(n)
SC: O(1)
*/

void usingInbuildMethods(vector<int> v, int n) {
    reverse(v.begin(), v.end());
}

/*
TC: O(n)
SC: O(1)
way efficient, not using left, right variables
*/

void reverseUsingSwapping(int arr [], int n) {
    for(int i=0;i<n/2;i++) {
       swap(arr[i], arr[n - i - 1]);
    }
}

/*
TC: O(n)
SC: O(n)
The depth of recursion here is approximately n/2. n/2 because each call reduces the problem size by 2 (one from the left and one from the right).
Since each stack frame requires some space (for l, r, and return addresses), and there are n/2 frames at most, the space used for these stack frames grows linearly with n
*/
void reverseUsingRecursion(int arr[], int l, int r) {
        if(l >= r) return;
        else {
            swap(arr[l], arr[r]);
            reverseUsingRecursion(arr, l + 1, r-1); //never use l++, r-- it passes old value (zsh: segmentation fault error if post inc/dec operator used for l and r)
        }
}

int main() {

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(int);
   // reverseUsingTempArray(arr, n);
   //reverseUsingTwoPointer(arr, n);
  // reverseSolo(arr, n);
  //vector<int> v = {1,2,3,4,5};
 // usingInbuildMethods(v, v.size());

   reverseUsingRecursion(arr, 0, n - 1);
   cout << endl << "reverseUsingRecursion, Reversed array:" << endl;
  for(int i=0;i<n;i++) {
    cout << arr[i] << " ";
  }
    return 0;
}
