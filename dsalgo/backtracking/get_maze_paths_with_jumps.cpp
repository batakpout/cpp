#include<iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
Approximate Time Complexity: The number of paths is exponential, roughly O(3^(n)) where n is the maximum of (dr - sr) and (dc - sc). 
This is because at each step, there are up to 3 choices (H, V, D), and the depth is up to n.
But since the step sizes vary, it's more precise to say it's exponential, possibly O(3^n) or higher.
roughly O(3^n+m)
Space Complexity: O(n^2) because:
Depth: O(n).
At each level, psf can be O(n).
So, O(n) * O(n) = O(n^2).
 */
void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    if (sr == dr && sc == dc) {
        cout << "=====reached base case====" << endl;
        cout << psf << endl;
        return;
    }

    vector<string> paths;

    // Horizontal moves
    cout << "Trying to go into horizontal: "<< endl;
    for (int ms = 1; ms <= dc - sc; ms++) {
        cout << "==Horizontal move passed,== " << " ms:  " << ms << ", sr: " << sr << ", sc: " << sc  << ", dc-sc: " << dc-sc << ", psf: " << psf << endl;
        cout << "==calling printMazePaths with = " << " ms:  " << ms << ", sr: " << sr << ", sc: " << sc + ms << ", psf: " << psf + "h" + to_string(ms) << endl;
        printMazePaths(sr, sc + ms, dr, dc, psf + "h" + to_string(ms));
        cout << "Horizontal: trying loop: " << ms + 1 << ", ms will be now: " << ms+1 << endl;
    }

    cout << "------------------------1------------------------" << endl;

    // Vertical moves
    cout << "Trying to go into Vertical: " << ", sr: " << sr << ",sc: " << sc << endl;
    for (int ms = 1; ms <= dr - sr; ms++) {
                cout << "==vertical move passed== " << " ms:  " << ms << ", sr: " << sr << ", sc: " << sc << ", dr-sr: " << dr-sr << ", psf: " << psf << endl;
          cout << "==calling printMazePaths with = " << " ms:  " << ms << ", sr: " << sr + ms << ", sc: " << sc << ", psf: " << psf + "v" + to_string(ms) << endl;                  
         printMazePaths(sr + ms, sc, dr, dc, psf + "v" + to_string(ms));
         cout << "Vertical: trying loop: ms :" << ", sr: " << sr << ", sc: " << sc  << ", ms will be now: " << ms+1<< " and sr+ ms: " << sr + ms+1 << endl;
    }
        cout << "------------------------2------------------------" << endl;


    // Diagonal moves
    cout << "Trying to go into Diagonal: " << ", sr: " << sr << ",sc: " << sc <<  endl;
    for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
          cout << "==Diagonal move passed== " << " ms:  " << ms << ", sr: " << sr << ", sc: " << sc <<  ", dr-sr: " << dr-sr << 
          ",dc-sc" << dc - sc << ", psf: " << psf << endl;
                    cout << "==calling printMazePaths with = " << " ms:  " << ms << ", sr: " << sr + ms << ", sc: " << sc + ms<< ", psf: " << psf + "d" + to_string(ms) << endl; 
        printMazePaths(sr + ms, sc + ms, dr, dc, psf + "d" + to_string(ms));
           cout << "Diagonal: trying loop: " << ms + 1 << ", ms will be now: " << ms+1<< endl;
    }
        cout << "------------------------3------------------------" << endl;

}

void printMazePathsv2(int sr, int sc, int dr, int dc, string psf) {
    if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
    }

    for (int ms = 1; ms <= dc - sc; ms++) {
        printMazePaths(sr, sc + ms, dr, dc, psf + "h" + to_string(ms));
    }

    for (int ms = 1; ms <= dr - sr; ms++) {
        printMazePaths(sr + ms, sc, dr, dc, psf + "v" + to_string(ms));
    }

    for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) {
        printMazePaths(sr + ms, sc + ms, dr, dc, psf + "d" + to_string(ms));
    }
}


int main() {
    cout << "Enter grid size: ";
    int n;
    cin >> n;
     printMazePaths(1,1,n,n,"");

    return 0;
}