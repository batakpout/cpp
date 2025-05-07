#include<iostream>
using namespace std;

bool search(int arr[], int n, int target) {

    for(int i=0;i<n;i++) {
        if(arr[i] == target) return true;
    }
    return false;
}

int main() {

    int arr [] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(int);
    bool res = search(arr, n, 42);

    cout << (res ? "true" : "false") << endl;

    return 0;
}