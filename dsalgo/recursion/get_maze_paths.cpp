/**
  - 62. Unique Paths
  - find optimized solution using DP [https://www.geeksforgeeks.org/tutorial-on-path-problems-in-a-grid-maze-or-matrix/]

 */

#include<iostream>
using namespace std;

vector<string> findMazePaths(int sr, int sc, int dr, int dc) {

     if (sr == dr && sc == dc) return {""};

     vector <string> path1;   
     vector <string> path2;   
    if(sc < dc)  path1 = findMazePaths(sr, sc+1, dr, dc);
    if(sr < dr)  path2 = findMazePaths(sr+1, sc, dr, dc);

    vector<string> paths;
    for(string s1: path1) {
        paths.push_back("h" + s1);
    } 

    for(string s2: path2) {
        paths.push_back("v" + s2);
    } 
    return paths;

}

int main() {
    cout << "Enter grid size: ";
    int n;
    cin >> n;
    vector<string> v = findMazePaths(1,1,n,n);
    cout << "maze paths: " << endl;
    for(int i=0;i<v.size();i++) {
        cout << v[i] << endl;
    }
    return 0;
}