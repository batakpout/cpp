#include <iostream>
#include <vector>
using namespace std;

/**
Function	        Order of Printing	            Time Complexity	    Space Complexity
display	Forward     (arr[0] to arr[n-1])	        O(n)	            O(n) (recursion_backtracking stack)
reverseDisplay	    Backward (arr[n-1] to arr[0])	O(n)	            O(n) (recursion_backtracking stack)
 */
// Forward display (prints array elements from index 0 to n-1)
void display(const vector<int>& arr, int idx, int l) {
    if (idx == l) {
        return;
    }
    cout << arr[idx] << endl;
    display(arr, idx + 1, l);
}

// Reverse display (prints array elements from index n-1 to 0)
void reverseDisplay(const vector<int>& arr, int idx, int l) {
    if (idx == l) {
        return;
    }
    reverseDisplay(arr, idx + 1, l);
    cout << arr[idx] << endl;
}

int main() {
    vector<int> a(5);
    
    cout << "Enter 5 array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    
    cout << "Displaying arr:" << endl;
    display(a, 0, a.size());
    
    cout << "Now displaying in reverse:" << endl;
    reverseDisplay(a, 0, a.size());
    
    return 0;
}