#include<iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

/**
 Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the input matrix.

Space Complexity: O(1) (constant space, no additional storage proportional to input size).
 */
void spiralPrint(const vector<vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    for (int j = 0; j < cols; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < rows; ++i) {
                cout << arr[i][j] << endl;
            }
        } else {
            for (int i = rows - 1; i >= 0; --i) {
                cout << arr[i][j] << endl;
            }
        }
    }
}

int main() {
    int row, col;
    cout << "Enter row size: ";
    cin >> row;
    cout << "Enter col size: ";
    cin >> col;

    vector<vector<int>> arr(row, vector<int>(col));
    cout << "Enter " << row << "x" << col << " array:" << endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "Entered array:" << endl;
    for (const auto& r : arr) {
        for (int val : r) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "printing wave display:" << endl;
    spiralPrint(arr);

    return 0;
}
