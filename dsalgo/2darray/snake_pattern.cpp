#include<iostream>
using namespace std;
/**
  O(rows * cols)
Snake pattern:
 12 →  45 →  23 →  67
 2 ←  56 ←  34 ←  89
 78 →  19 →  35 →  91
 43 ←  8 ←  62 ←   4
 */


void snakePattern(vector<vector<int>> & matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0;i<rows;i++) {
        if(i%2 == 0) {
            for(int j=0;j<cols;j++) {
                cout << matrix[i][j] << " ";
            }
        } else {
           for(int j=cols-1;j>=0;j--) {
                cout << matrix[i][j] << " ";
            }  
        }
        cout << endl;
    }
}

int main() {
vector<vector<int>> arr = {
        {12, 45, 23, 67},
        {89, 34, 56,  2},
        {78, 19, 35, 91},
        {4, 62,  8, 43}
    };
    snakePattern(arr);
    return 0;
}