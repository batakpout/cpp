/*
To compute the weighted sum:
    getWSum(l, r) = ∑ from i=l to r of (i−l+1)⋅arr[i]
                  = ∑ from i=l to r of i⋅arr[i] − (l−1)⋅∑ from i=l to r of arr[i]

1⋅arr[0]+2⋅arr[1]+3⋅arr[2]=1⋅2+2⋅3+3⋅5=2+6+15=23

To do this efficiently:
1. Build two prefix sum arrays:
   - preSum[i] = arr[0] + arr[1] + ... + arr[i]
   - preWSum[i] = 1⋅arr[0] + 2⋅arr[1] + ... + (i+1)⋅arr[i]

2. Then we can compute:
    getWSum(l, r) = (preWSum[r] − preWSum[l−1]) − (l−1)⋅(preSum[r] − preSum[l−1])

This reduces each query to O(1) time after O(n) preprocessing.
*/
#include<iostream>
using namespace std;
vector<int> buildPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> preSum(n);
    preSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        preSum[i] = preSum[i - 1] + arr[i];
    }
    return preSum;
}

vector<int> buildWeightedPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> preWSum(n);
    preWSum[0] = 0; // 0 * arr[0]

    for (int i = 1; i < n; ++i) {
        preWSum[i] = preWSum[i - 1] + i * arr[i];
    }

    return preWSum;
}

//pass prefix_sum and weighted_prefix_sum and O(1) op. for the weightedsum
int getWeightedSum(int l, int r, const vector<int>& preSum, const vector<int>& preWSum) {
    int weightedPart = preWSum[r] - (l > 0 ? preWSum[l - 1] : 0);
    int plainPart = preSum[r] - (l > 0 ? preSum[l - 1] : 0);
    return weightedPart - (l - 1) * plainPart;
}

int main() {

    vector<int> arr = {1,2,3,4,5,6};
    vector<int> preSum = buildPrefixSum(arr);
    vector<int> preWSum = buildWeightedPrefixSum(arr);

    int result = getWeightedSum(2, 4, preSum, preWSum);
    /**
     * answer should be 1*arr[2] + 2*arr[3]
     */
    cout << result << endl;
    return 0;
}
