#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
};