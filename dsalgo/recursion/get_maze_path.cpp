#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        return {""};
    }

    vector<string> hpaths;
    vector<string> vpaths;

    if (sc < dc) {
       hpaths = getMazePaths(sr, sc + 1, dr, dc);
    }

    if (sr < dr) {
         vpaths = getMazePaths(sr + 1, sc, dr, dc);
    }

    vector<string> paths;
    for(string hpath: hpaths) {
        paths.push_back("h" + hpath);
    }
    for(string vpath: vpaths) {
        paths.push_back("v" + vpath);
    }

    return paths;
}

int main() {
    int n = 3;
    vector<string> res = getMazePaths(1,1,n,n);
    for(int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
}
