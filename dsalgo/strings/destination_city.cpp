/**
* LC: E: 1436. Destination City
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi.
Return the destination city, that is, the city without any path outgoing to another city.
It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
Example 1: Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]] Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2: Input: paths = [["B","C"],["D","B"],["C","A"]] Output: "A"
Explanation: All possible trips are:
Example 3: Input: paths = [["A","Z"]] Output: "Z"
 */
#include<iostream>
#include<unordered_map>
#include <unordered_set>
using namespace std;

//TC: O(N)
//SC: O(N) but will be less than that
string destCityUsingHashMap(vector<vector<string>>& paths) {
        unordered_map<string, int> m;
        for (auto & path: paths) {
            m[path[0]] = 1;
        }
        for (auto & path: paths) {
            if (m[path[1]] != 1) return path[1];
        }
    return "";
}
//TC: O(N)
//SC: O(N) but will be less than that
string destCityUsingHashSet(vector<vector<string>>& paths) {
    unordered_set<string> s;
    for (auto & path: paths)
        s.insert(path[0]);

    for (auto & path: paths)
        if (s.find(path[1]) == s.end()) return path[1];

    return "";
}

int main() {

    vector<vector<string>> arr_2d;
    int row, col;

    cout << "Enter row size: ";
    cin >> row;
    cout << "Enter col size: ";
    cin >> col;

    cout << "Enter " << row << "x" << col << " string array" << endl;
    arr_2d.resize(row, vector<string>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "enter element [" << i << "][" << j << "]: ";
            cin >> arr_2d[i][j];
        }
    }

    cout << "Entered array:" << endl;
    for (const auto& r : arr_2d) {
        for (string val : r) cout << val << " ";
        cout << endl;
    }

    string res = destCityUsingHashSet(arr_2d);
    cout << "destination city is:"  << res;

    return 0;
}