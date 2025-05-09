/**
 *comming down from stairs with 1 or 2 or 3 steps
 * find optimized solutions here: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
 Time complexity:
 * at each level you branch into 3 recursive calls (n-1, n-2, and n-3). This branching creates a ternary recursion tree:At level 0: 1 call At level 1: 3 calls At level 2: 3² calls
At level n: 3ⁿ calls
Thus, the total number of recursive calls is O(3ⁿ). Also O(n) for each string concatenation operation so
O(3ⁿ * n)

 */

#include<iostream>
using namespace std;
int callCount = 0;

// is it backtracking?
void findStairPaths(int n, string psf) {

   callCount++; 
    if(n == 0) {
        cout << psf << endl;
        return;
    }
    if(n < 0) return;
    
    findStairPaths(n-1, psf + "1");
    findStairPaths(n-2, psf + "2");
    findStairPaths(n-3, psf + "3");

}

/**
 TC: O(n × T(n)) = O(n × 3ⁿ)
Same as before — but avoids recomputation, so it's much faster in practice.
for n = 25 above methods hangs but this method works
for n = 25 only 76 function calls but for n = 30 hangs becoz
the function is trying to build and return a vector of ~53 million strings, each of length ~10–30.
That is very memory intensive and slow, because: You're dynamically allocating space for tens of millions of strings.You're doing millions of string concatenations like "1" + path, "2" + path, etc.
The vector<string> returned for each subproblem gets copied and joined into even bigger vectors.
It's not truly hanging — it's just struggling with memory allocation and massive string manipulation.
 */
vector<string> memoized(int n, unordered_map<int, vector<string>>& memo) {
       callCount++; 

    if (n == 0) return {""}; 
    if (n < 0) return {}; 
    if (memo.count(n)) return memo[n]; //count check if key exists in map and return 1 else 0


    vector<string> result;

    for (string path : memoized(n - 1, memo)) {
        result.push_back("1" + path);
    }
    for (string path : memoized(n - 2, memo)) {
        result.push_back("2" + path);
    }
    for (string path : memoized(n - 3, memo)) {
        result.push_back("3" + path);
    }
    memo[n] = result;
    return result;
}

/*
 If I am interested in only returning no of paths instead of storing each path
*/

int nonMemorizedVersion(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    return nonMemorizedVersion(n - 1) +
              nonMemorizedVersion(n - 2) +
              nonMemorizedVersion(n - 3);

}

/**
 here memoization works well, computes result for large inputs
 */
long long memoizedVersion(int n, unordered_map<int, long long>& memo) {
    if (n == 0) return 1L;
    if (n < 0) return 0L;
    if (memo.count(n)) return memo[n];

    memo[n] = memoizedVersion(n - 1, memo) +
              memoizedVersion(n - 2, memo) +
              memoizedVersion(n - 3, memo);

    return memo[n];
}

int main() {
    cout << "Enter number of stairs: ";
    int s;
    cin >> s;
    findStairPaths(s, "");
    //unordered_map<int, vector<string>> memo;
    //vector<string> result = memoized(s, memo);
    //cout << "Ways to come down " << s << " stairs with 1 or 2 or 3 steps\n";
    /* for(const auto &s: result) {
        cout << s << endl;
    }*/
   // cout << "Function calls: " << callCount << endl;

    //int c = nonMemorizedVersion(s);
   // unordered_map<int, long long> memo;
   // long long c = memoizedVersion(s, memo);
   // cout << "total paths: " << c << endl;
    return 0;
}