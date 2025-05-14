#include<iostream>
using  namespace std;
/**
    length of 1D array calculation:
    leftSide            + lowerSide             + rightSide             + upperSide
    (max_r - min_r + 1) + (max_c - min_c + 1)   + (max_r - min_r + 1)   + (max_c - min_c + 1) -> 5 -1 = 4 + 1 = 5 items from 1 to 5
    ==> 2 * (max_r - min_r + 1) + 2 * (max_c - min_c + 1)
    ==> 2 * ((max_r - min_r) + (max_c - min_c))
 */
void reverse(vector<int>& arr_1d, int left, int right) {
    while (left < right) {
        swap(arr_1d[left], arr_1d[right]);
        left++;
        right--;
    }
}

vector<int> rotate(vector<int>& arr_1d, int k) {
    int n = arr_1d.size();
    k = k % n;
    if (k < 0) {
        k = k + n;
    }
    reverse(arr_1d, 0, n - k - 1);
    reverse(arr_1d, n - k, n - 1);
    reverse(arr_1d, 0, n - 1);
    return arr_1d;
}

vector<int> make1DFromShell(vector<vector<int>>& arr_2d, int s) {
    int min_r = s - 1;
    int max_r = arr_2d.size() - s;
    int min_c = s - 1;
    int max_c = arr_2d[0].size() - s;

    int size = 2 * ((max_r - min_r) + (max_c - min_c));
    vector<int> arr_1d(size);
    int i = min_r, j = min_c, idx = 0;

    while (i <= max_r) {
        arr_1d[idx++] = arr_2d[i++][j];
    }
    min_c++;

    i = max_r; j = min_c;
    while (j <= max_c) {
        arr_1d[idx++] = arr_2d[i][j++];
    }
    max_r--;

    i = max_r; j = max_c;
    while (i >= min_r) {
        arr_1d[idx++] = arr_2d[i--][j];
    }
    max_c--;

    i = min_r; j = max_c;
    while (j >= min_c) {
        arr_1d[idx++] = arr_2d[i][j--];
    }

    return arr_1d;
}

void makeShellFrom1D(vector<vector<int>>& arr_2d, vector<int>& arr_1d, int s) {

    int min_r = s - 1;
    int max_r = arr_2d.size() - s;
    int min_c = s - 1;
    int max_c = arr_2d[0].size() - s;

    int i = min_r, j = min_c, idx = 0;

    while (i <= max_r) {
        arr_2d[i++][j] = arr_1d[idx++];
    }
    min_c++;

    i = max_r; j = min_c;
    while (j <= max_c) {
        arr_2d[i][j++] = arr_1d[idx++];
    }
    max_r--;

    i = max_r; j = max_c;
    while (i >= min_r) {
        arr_2d[i--][j] = arr_1d[idx++];
    }
    max_c--;

    i = min_r; j = max_c;
    while (j >= min_c) {
        arr_2d[i][j--] = arr_1d[idx++];
    }
}

void shellRotate(vector<vector<int>>& arr_2d, int s, int k) {
    vector<int> arr_1d = make1DFromShell(arr_2d, s);
    arr_1d = rotate(arr_1d, k);
    makeShellFrom1D(arr_2d, arr_1d, s);
}

int main() {
    vector<vector<int>> arr_2d;
    int row, col;

    cout << "Enter row size: ";
    cin >> row;
    cout << "Enter col size: ";
    cin >> col;

    cout << "Enter " << row << "x" << col << " array" << endl;
    arr_2d.resize(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "enter element [" << i << "][" << j << "]: ";
            cin >> arr_2d[i][j];
        }
    }

    cout << "Entered array:" << endl;
    for (const auto& r : arr_2d) {
        for (int val : r) cout << val << " ";
        cout << endl;
    }

    int s, k;
    cout << "Enter the shell number to rotate: ";
    cin >> s;
    cout << "Enter number to rotate it by: ";
    cin >> k;

    shellRotate(arr_2d, s, k);

    cout << "Printing shell rotated array:" << endl;
    for (const auto& r : arr_2d) {
        for (int val : r) cout << val << " ";
        cout << endl;
    }

    return 0;
}

/**
 make1DFromShell: Time Complexity: O(m), where m is the number of elements in the shell.
Space Complexity: O(m), as it creates a new 1D array of size m.

rotate: Time Complexity: O(m), as it performs three reverses, each taking O(m/2) time.
Space Complexity: O(1), as it operates in-place on the input array.

makeShellFrom1D: Time Complexity: O(m), similar to make1DFromShell, as it iterates over the shell elements.
Space Complexity: O(1), as it modifies the input 2D array in-place.

shellRotate:
Time Complexity: Dominated by the three methods it calls:make1DFromShell: O(m),rotate: O(m), makeShellFrom1D: O(m)
Total: O(m) + O(m) + O(m) = O(m)

Space Complexity:
The main additional space is the 1D array of size m created in make1DFromShell. So, O(m)
 */