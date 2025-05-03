#include<iostream>
using namespace std;
/**
The outer loop runs n-k+1 times. as i runs from 0 to n-k --> n-k+1
The inner loop runs k times for each subarray.
Total operations: roughly O((n-k+1) * k) → O(n*k) -> O(n²) when k ≈ n/2.
 */
int maxSumKSubArrays(vector<int> &v, int k) {
    int n = v.size();
    if(k > n) return -1;

    int maxSum = INT_MIN;
    for(int i=0;i<=n-k;i++) {
        int currSum = 0;
        for(int j=i;j<i+k;j++) {
            currSum += v[j];
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

//O(N)
int maxSumKArray(vector<int> &v, int k) {
    int n = v.size();
    if(n < k) return -1;
    int windowSum;
    for(int i=0;i<k;i++) {
        windowSum += v[i];
    }
    int maxSum = windowSum;

    for(int i=k;i<n;i++) {
        windowSum += v[i] - v[i-k];
        maxSum = max(windowSum, maxSum);
    }
    return maxSum;
}

int main() {
    cout << "Enter array size: ";
    int n;
    cin>>n;
    vector<int>v(n);
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout << "Enter sub array size: ";
    int k;
    cin>>k;
    //int res = maxSumKSubArrays(v, k);
    int res = maxSumKArray(v, k);
    cout << "Max Sum of K subarrays: " << res << endl;

}