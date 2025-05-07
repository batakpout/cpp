#include<iostream>
using namespace std;

/**
Complexity	Value	        Explanation
Time	    O(n × m × p)	Due to the triple-nested loop.
Space	    O(n × p)	    Due to the result matrix arr3.

n = rows of arr1
m = len(arr1[0]) = len(arr2) (cols of arr1 and rows of arr2)
p = len(arr2[0]) (cols of arr2)
 */
vector<vector<int>> multiply(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2) {
    if (arr1[0].size() != arr2.size()) {
        throw invalid_argument("Number of columns in 'arr1' must match rows in 'arr2'");
    }

    int rows = arr1.size();
    int cols = arr2[0].size();
    int inner = arr2.size(); // same as arr1[0].size()

    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < inner; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return result;
}

int main() {

      int rows, cols;
      cout << "enter rows: ";
      cin >> rows; 
      cout << "enter cols: ";
      cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "enter matrix: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "entered matrix: " << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
          cout << '\n';
    }
    vector<vector<int>> res = multiply(matrix, matrix);
    cout << "result: " << endl;
    for (const auto& row : res) {
        for (int val : row) {
            cout << val << " ";
        }
          cout << '\n';
    }
    return 0;
}