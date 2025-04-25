#include<iostream>
using namespace std;
/**
Time Complexity: O(n * m), where n is the number of rows and m is the number of columns.

Space Complexity: The method uses a constant amount of extra space (variables i, j, k), regardless of the input size.

The input array is not counted toward space complexity since it’s part of the input.

Thus, the space complexity is O(1) (constant space).
"""
 */
void diagonalTraverse(const vector<vector<int>> & matrix) { // & avoid copies, read only [const]
    int rows = matrix.size();
    int cols = matrix[0].size();
    int j,k;
    for(int i=0;i<cols;i++) {
        j = i;
        k = 0;
        while(j < cols && k < rows) {
            cout << matrix[k][j] << " ";
            j++;
            k++;
        }
    }
}

int main() {

    int rows, cols;
    cout << "Enter row size: ";
    cin >> rows;
    cout << "Enter col size: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        throw invalid_argument("Matrix dimensions must be positive");
    }

    cout << "Enter " << rows << "x" << cols << " array:\n";
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            if (!(cin >> matrix[i][j])) { // Attempts to read an integer from standard input Inverts the result - becomes true if the extraction fails
                throw runtime_error("Invalid input - expected integer");
            }
        }
    }

    cout << "\nEntered matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    cout << "Printing Diagonal Elements:\n";
    diagonalTraverse(matrix);
    cout << endl;
    return 0;
}