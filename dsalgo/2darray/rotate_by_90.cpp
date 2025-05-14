  #include<iostream>
 using namespace std;
 void transpose(vector<vector<int>>& mat, int n) {
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
}

void reverse(int left, int right, vector<int> &arr) {
    while(left<right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotateBy90(vector<vector<int>> & arr) {
    int n = arr.size();
    transpose(arr, n);
    for(int i=0;i<n;i++) {
        reverse(0, n-1, arr[i]);
    }
}

int main() {
    vector<vector<int>> v = {
        {1,2,3,4,5},
        {6,7,8,9,1},
        {0,2,5,8,2},
        {5,3,1,5,7},
        {8,4,9,1,2},
    };

   rotateBy90(v);
   for(int i=0;i<v.size();i++) {
    for(int j=0;j<v[0].size();j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
   } 
   cout << endl;
}