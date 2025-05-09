 #include<iostream>
 using namespace std;
 //O(n*n)
 void transpose(vector<vector<int>>& mat, int n) {
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
    }