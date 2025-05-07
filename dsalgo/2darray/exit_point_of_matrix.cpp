#include<iostream>
using namespace std;
/**
 
 r=4, c=4
 0 0 1 0 
 1 0 0 0 
 0 0 0 0 
 1 0 1 0
 ans: i=1, j=3
O(r*C)
 */

pair<int, int> exitPoint(const vector<vector<int>>& arr) {
    int i = 0, j = 0, direction = 0;
    int rows = arr.size();
    int cols = arr[0].size();

    while (true) {
        direction = (arr[i][j] + direction) % 4;

        if (direction == 0) {
            j++;  // move right
        } else if (direction == 1) {
            i++;  // move down
        } else if (direction == 2) {
            j--;  // move left
        } else if (direction == 3) {
            i--;  // move up
        }

        // Check boundaries
        if (i < 0) {
            i++;
            break;
        } else if (j < 0) {
            j++;
            break;
        } else if (i >= rows) {
            i--;
            break;
        } else if (j >= cols) {
            j--;
            break;
        }
    }

    return {i, j};

}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 0}
    };

    pair<int, int> result = exitPoint(grid);
    cout << "Exit point: (" << result.first << ", " << result.second << ")\n";
    return 0;
}