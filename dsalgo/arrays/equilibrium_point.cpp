#include<iostream>
using namespace std;

//O(N^2)
bool isEquilibriumPointInArrayNaive(vector<int> & arr) {
    int n = arr.size();
   
    for(int i=0;i<n;i++) {
         int left = 0;
         int right = 0;
         for(int j=0;j<i;j++) {
            left += arr[j];
         }
         for(int k=i+1;k<n;k++) {
            right += arr[k];
         }
         if(left == right) return true;
    }
    return false;
}
/**
 build prefix and suffix arrays 
 e.g for  [3, 4,  8, -9, 9,   7] at 8 we have equilibrium point
 preSum = [3, 7,  15, 6, 15, 22]
 sufSum = [22,19, 15, 7, 16,  7]

 for all elements except corner ones check if
 preSum[i-1] == sufSum[i+1]
 e.g for index = 2 at 8, we have 7 on both sides
 */

//Simple approach with O(n) complexity
bool isEquilibriumPointInArrayOptimized(vector<int> & arr) {
    int n = arr.size();
    int rs = 0;
    for(int i=0;i<n;i++) {
        rs += arr[i];
    }

    int ls = 0;
    for(int i=0;i<n;i++) {
         rs -= arr[i];   
         if(ls == rs) return true;
         ls += arr[i];
    }
    return false;
}

int main() {

    vector<int> v = {3,4,8,-9,20,6};
    //bool res = isEquilibriumPointInArrayNaive(v);
    bool res = isEquilibriumPointInArrayOptimized(v);
    cout << res << endl;

    return 0;
}