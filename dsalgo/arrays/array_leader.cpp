#include<iostream>
using namespace std;

//O(n^2)
vector<int> arrayLeader(vector<int> & arr) {
    int n = arr.size();
    vector<int> res;
    for(int i=0;i<n;i++) {
        int j;
        for(j=i+1; j<n;j++) {
            if(arr[j] > arr[i]) break;
        }
        if(j == n) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

//O(N)TC, O(1) SC
vector<int> optimizedArrayLeader(vector<int> & arr) {
    vector<int> res; 
    int n = arr.size();

    // Start with the rightmost element
    int maxRight = arr[n - 1]; 

    // Rightmost element is always a leader
    res.push_back(maxRight); 
    
    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] >= maxRight) {
            maxRight = arr[i]; 
            res.push_back(maxRight); 
        }
    }

    // Reverse the result array to maintain
    // original order
    reverse(res.begin(), res.end());
    
    return res; 
}

int main() {

    int n;
    cout << "enter array size: ";
    cin >> n;
    vector<int> v(n);
    cout << "enter " << n << " array elements:\n";
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    cout << "array leaders:\n";
    //vector<int> r = arrayLeader(v);
    vector<int> r = optimizedArrayLeader(v);
    for(int i=0;i<r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}