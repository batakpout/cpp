/**
  - 62. Unique Paths
  - find optimized solution using DP [https://www.geeksforgeeks.org/tutorial-on-path-problems-in-a-grid-maze-or-matrix/]

Time Complexity:
The binomial coefficient:
O((m + n))   *  length of each path 
 (( m    ))
(dr - sr) = m and (dc - sc) = n,

Example For a grid where dr - sr = 2 and dc - sc = 2 (a 3x3 grid, starting at (0,0) and ending at (2,2)): Number of paths: ( 2 + 2  2 ) bionomial confficeint =6. Each path has length 4 (e.g., "hhvv", "hvhv", etc.). Total work: 6 ⋅ 4 = 24 operations.

For an n × n n×n grid, the time complexity is O(4 ^n * square_root(n)).
 */

#include<iostream>
using namespace std;

void findMazePaths(int sr, int sc, int dr, int dc, string psf) {

     if(sc > dc || sr > dr) return;
     if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
     }

    findMazePaths(sr, sc+1, dr, dc, psf + "h1");
    findMazePaths(sr+1, sc, dr, dc, psf + "v1");

}

int main() {
    cout << "Enter grid size: ";
    int n;
    cin >> n;
    findMazePaths(1,1,n,n,"");
    return 0;
}
/**
 Why Binomial Coefficient? Problem Representation: You start at (sr, sc) and need to reach (dr, dc). Let’s define: Right moves ('h'): n = dc - sc (number of columns to traverse). Down moves ('v'): m = dr - sr (number of rows to traverse). Every path from (sr, sc) to (dr, dc) consists of exactly m down moves and n right moves, in some order. The total moves in any path: m + n. Counting Paths: The problem reduces to: How many distinct sequences of m downs and n rights exist? This is equivalent to choosing m positions (for down moves) out of m + n total moves (the rest are right moves). The number of such sequences is given by the binomial coefficient: ( m + n m ) = ( m + n n ) ( m m+n ​ )=( n m+n ​ ) Example: Suppose m = 2 (down twice) and n = 2 (right twice). Total moves: 2 + 2 = 4. The number of unique paths is ( 4 2 ) = 6 ( 2 4 ​ )=6: "vvhh", "vhvh", "vhhv", "hvvh", "hvhv", "hhvv". Why Does This Affect Time Complexity? Recursive Tree: The function explores all possible paths by branching at each step (right or down). The recursion tree has: Leaves: Each leaf corresponds to a unique path (m + n levels deep). Nodes: The number of nodes is proportional to the number of paths, ( m + n m ) ( m m+n ​ ). Work per Path: Each path requires O(m + n) operations (appending 'h' or 'v' at each step). Thus, the total work is: O ( ( m + n m ) ⋅ ( m + n ) ) O(( m m+n ​ )⋅(m+n)) Approximation: Using Stirling’s approximation, ( 2 n n ) ≈ 4 n π n ( n 2n ​ )≈ πn ​ 4 n ​ for m = n m=n. So, for an n × n n×n grid, the time complexity is roughly: O ( 4 n n ⋅ n ) = O ( 4 n n ) O( n ​ 4 n ​ ⋅n)=O(4 n n ​ ) This grows exponentially with grid size.
 */