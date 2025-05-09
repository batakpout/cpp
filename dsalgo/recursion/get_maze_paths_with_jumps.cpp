
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        return {""};
    }

    vector<string> paths;

    // Horizontal moves
    for (int ms = 1; ms <= dc - sc; ms++) {
        vector<string> hpaths = getMazePaths(sr, sc + ms, dr, dc);
        for (string hpath : hpaths) {
            paths.push_back("h" + to_string(ms) + hpath);
        }
    }

    // Vertical moves
    for (int ms = 1; ms <= dr - sr; ms++) {
        vector<string> vpaths = getMazePaths(sr + ms, sc, dr, dc);
        for (string vpath : vpaths) {
            paths.push_back("v" + to_string(ms) + vpath);
        }
    }

    // Diagonal moves
    for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
        vector<string> dpaths = getMazePaths(sr + ms, sc + ms, dr, dc);
        for (string dpath : dpaths) {
            paths.push_back("d" + to_string(ms) + dpath);
        }
    }

    return paths;
}


int main() {
    cout << "Enter grid size: ";
    int n;
    cin >> n;
     vector<string> res = getMazePaths(1,1,n,n);
    for(int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }

    return 0;
}