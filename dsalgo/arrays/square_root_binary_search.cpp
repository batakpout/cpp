#include<iostream>
using namespace std;

//TC: O(squareRoot(N))
int squareRootNaive(int n) {
    int i=1;
    while(i*i<=n) 
     i++;
    return i-1; 
}
/*
The floor of the square root of x cannot be more than x/2 when x > 1
TC: O(log(N))
*/
int usingBinarySearch(int n) {
    if(n ==0 || n == 1) return n;

    int low = 0, high = n/2;
    int mid, sqr ,ans;
    while(low <= high) {
        mid = low + (high-low)/2;
        sqr = mid*mid;
        if(sqr == n) return mid;
        if(sqr > n) high = mid - 1;
        else {
            low = mid+1;
            ans = mid;
        }
    }
    return ans;
}

int main() {
    int arr [] = {1,2,3,4,11,27,37,50};

    for(int i=0;i<8;i++) {
    int res1 = squareRootNaive(arr[i]);
    int res2 = usingBinarySearch(arr[i]);
     cout << "res1: " << res1 << endl;
     cout << "res2: " << res1 << endl;
    }
}