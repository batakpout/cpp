#include <iostream>
#include <vector>
using namespace std;
/**
Complexity	    Value	    Explanation
Time	        O(till²)	Due to the nested loops (triangular number sum).
Space	        O(till²)	Due to the stored matrix (Pascal's Triangle).

for i = 0, j runs 1 times, for i = 1 , 2 times, for i = 2, 3 times, for i=3, 4 times and so on and so forth
its 1 + 2 + 3 ... + (till + 1) times ==> (till + 1) (till + 2) / 2 => O(till * till) complexity

Triangular Number Sum refers to the total number of elements in Pascal’s Triangle up to row till
 */
vector<vector<int>> pascalTriangle(int till) {
    vector<vector<int>> matrix;

    for (int i = 0; i <= till; ++i) {
        vector<int> row;
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                row.push_back(1);
            } else {
                row.push_back(matrix[i - 1][j] + matrix[i - 1][j - 1]);
            }
        }
        matrix.push_back(row);
    }

    return matrix;
}

int main() {
    cout << "Generate till...: ";
    int till;
    cin >> till;
    vector<vector<int>> result = pascalTriangle(till);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
