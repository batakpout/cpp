#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
Both approaches[recursion one and backtracking one] have the same asymptotic time complexity of O(3^n), but this recursive approach has:
Higher constant factors[i.e performs operations that take more CPU cycles at each step.]
More memory overhead
Potentially slower real-world performance due to data structure operations

If you were to implement memoization (caching results of subproblems), this recursive approach might benefit more significantly as it explicitly returns values that could be cached, potentially reducing the complexity to O(n). 
 */
vector<string> getStairPaths(int n) {
    if (n == 0) {
        return {""};
    } else if (n < 0) {
        return {};
    }

    vector<string> paths1 = getStairPaths(n - 1);
    vector<string> paths2 = getStairPaths(n - 2);
    vector<string> paths3 = getStairPaths(n - 3);

    vector<string> paths;

    for (string path : paths1) {
        paths.push_back("1" + path);
    }

    for (string path : paths2) {
        paths.push_back("2" + path);
    }

    for (string path : paths3) {
        paths.push_back("3" + path);
    }

    return paths;
}
