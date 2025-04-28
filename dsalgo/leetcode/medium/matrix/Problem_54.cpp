#include<iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> & matrix) {
    vector<int> result;
    int row = matrix.size();
    int col = matrix[0].size();
    int min_r = 0, min_c = 0;
    int max_r = row - 1, max_c = col - 1;
    int count = 0;
    int total = row * col;

    while (count < total) {
            for (int j = min_c; j <= max_c && count < total; j++) {
                result.push_back(matrix[min_r][j]);
                count++;
            }
            min_r++;

            for (int i = min_r; i <= max_r && count < total; i++) {
                result.push_back(matrix[i][max_c]);
                count++;
            }
            max_c--;

            for (int j = max_c; j >= min_c && count < total; j--) {
                result.push_back(matrix[max_r][j]);
                count++;
            }
            max_r--;

            for (int i = max_r; i >= min_r && count < total; i--) {
                result.push_back(matrix[i][min_c]);
                count++;
            }
            min_c++;
        }
        return result;
}
