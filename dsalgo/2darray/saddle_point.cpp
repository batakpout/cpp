#include<iostream>
using namespace std;
/**
 n: rows
m: cols
So for each row, I do: O(m) work to find the row min, O(n) work to check column max
Total time per row = O(m + n)
Total for all rows = O(n * (m + n))

Final Time Complexity: O(mn + n*n)
 */
void saddlePoint(vector<vector<int>> & arr) {
    int n = arr.size();
    int sv;
    for(int i=0;i<n;i++) {
        sv=0;
        for(int j=1;j<n;j++) {
            if(arr[i][j] < arr[i][sv]) sv = j; 
        }
        bool flag = true;
        int k=0;
        while(k<arr[i].size()) {
            if(arr[k][i] > arr[i][sv]) flag = false;
         k++;
         }
        if(flag) {
            cout << "saddle-point: " << i << "," << sv << endl; 
            return;
         }
    
    }
    cout << "Invalid input" << endl;
}

int main() {

    vector<vector<int>> arr = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {1,2,11, 12, 31},
        {1,2,3,7,8}
    };
    saddlePoint(arr);
    return 0;
}