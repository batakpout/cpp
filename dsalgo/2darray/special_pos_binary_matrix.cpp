/**
 * LC : E: 1582. Special Positions in a Binary Matrix
 * A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1

Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 */

//TC: O[(n*m) * O(m+n)]
#include<iostream>
using namespace std;
int naiveApproach(vector<vector<int>> & mat) {
   int m = mat.size();
   int n = mat[0].size();
    int result = 0;

    for (int row=0;row<m;row++) {
      for (int col=0;col<n;col++) {
          if (mat[row][col] == 0)
              continue;
          bool special = true;
          //col check
          for (int r=0; r<m;r++) {
              if (r != row && mat[r][col] == 1) {
                  special = false;
                  break;
              }
          }
         if (special) {
             //row check
             for (int c=0;c<n;c++) {
                 if (c != col && mat[row][c] == 1) {
                     special = false;
                     break;
                 }
             }
         }
          if (special)
              result++;
      }
    }
 return result;
}

/**
 * TC: O(n*m)
 * SC: O(n+m)
 */
int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
    for (int row=0;row<m;row++) {
        for (int col=0;col<n;col++) {
            if (mat[row][col] == 1) {
                rowCount[row]++;
                colCount[col]++;
            }
        }
    }
    int result=0;
    for (int row=0;row<m;row++) {
        for (int col=0;col<n;col++) {
            if (mat[row][col] == 0) continue;
            if (rowCount[row] == 1 && colCount[col] == 1) {
                result++;
            }
        }
    }
  return result;
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
    int res = numSpecial(arr_2d);
    cout << "result: " << res;
    return 0;
}