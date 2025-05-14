#include<iostream>
using namespace std;
/**

Condition: the 2d array is already sorted in both rows and columns
--> If the matrix is square or nearly square, stairCaseSearch is better (O(rows + cols)).
--> If the matrix has a very large number of columns compared to rows, searchMatrix (row-wise binary search)
    is better (O(rows × log cols)).
--> space complexity for both: O(1)
 */
bool stairCaseSearch(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
    int i=0, j = cols-1;
    while(i < rows && j >=0) {
        if(matrix[i][j] == target) return true;
       
        if(target > matrix[i][j]) ++i;
        else --j;
    }
    return false;
}

bool binarySearch(int i, int low, int high, int target, const vector<vector<int>> & matrix) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(matrix[i][mid] == target) return true;
        else if(matrix[i][mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

bool usingBinarySearch(vector<vector<int>> & matrix, int target) {
    for(int i = 0;i<matrix.size(); i++) {
        int low = 0;
        int high = matrix[i].size() - 1;
        if(binarySearch(i, low, high, target, matrix)) return true;
    }
    return false;
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
    int target;
    cout << "Enter target:\n";
    cin >> target;
    cout << "Searching matrix for taget:\n";
    cout << (stairCaseSearch(matrix, target) ? "true" : "false") << endl;
    cout << (usingBinarySearch(matrix, target) ? "true" : "false") << endl;
    cout << endl;
    return 0;
    return 0;

}