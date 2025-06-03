 #include<iostream>
 using namespace std;
 //O(n*n)
 /**
  * this implementation will only work for square matrix becoz this assume
    mat[i][j] and mat[j][i] both exist, which is only guaranteed if mat.size() == mat[0].size() (square matrix).
  */
 void transpose(vector<vector<int>>& mat, int n) {
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(i != j)
                    swap(mat[i][j], mat[j][i]);
            }
        }
        
    }

//for any matrix
//TC: O(n*m), SC: O(n*m) but since it is used for result so it is ignored and we say O(1)
 void transpose(vector<vector<int>>& mat, int n) {
        int cols = mat[0].size();
        int rows = mat.size();
        vector<vector<int>> res(cols, vector<int>(rows));

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                res[j][i] = mat[i][j];
            }
        }
        
    }