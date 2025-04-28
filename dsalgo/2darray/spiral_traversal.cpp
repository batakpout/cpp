#include<iostream>
using namespace std;

void spiralTraversal(int arr[][6], int rows, int cols) {  // Must specify column size 

    int total = rows * cols;
    int min_r = 0, min_c = 0;
    int max_r = rows - 1, max_c = cols - 1;
    int count = 0;
  
    while (count < total) {
        // Traverse down the leftmost column
        for (int i = min_r; i <= max_r && count < total; i++) {
            cout << arr[i][min_c] << " ";
            count++;
        }
        cout << endl;
        min_c++;
        
        // Traverse right along the bottom row
        for (int j = min_c; j <= max_c && count < total; j++) {
            cout << arr[max_r][j] << " ";
            count++;
        }
        cout << endl;
        max_r--;
        
        // Traverse up the rightmost column
        for (int i = max_r; i >= min_r && count < total; i--) {
            cout << arr[i][max_c] << " ";
            count++;
        }
        cout << endl;
        max_c--;
        
        // Traverse left along the top row
        for (int j = max_c; j >= min_c && count < total; j--) {
            cout << arr[min_r][j] << " ";
            count++;
        }
        cout << endl;
        min_r++;
    }
}

int main() {

     int arr[5][6] = {
        {1,  2,  3, 4, 5, 61},
        {12, 19, 3, 2, 4, 84},
        {13, 12, 5, 6, 7, 82},
        {15, 18, 1, 2, 3, 81},
        {18, 11, 5, 6, 7, 8}
    };
    
    spiralTraversal(arr, 5, 6);
    return 0;
}