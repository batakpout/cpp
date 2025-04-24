#include <iostream>
#include <vector>
using namespace std;

// First occurrence of target (returns -1 if not found)
int firstOcc(const vector<int>& arr, int l, int idx, int target) {
    if (idx == l) {
        return -1;
    }
    int res = firstOcc(arr, l, idx + 1, target);
    if (arr[idx] == target) {
        return idx;
    } else {
        return res;
    }
}

// Last occurrence of target (returns -1 if not found)
int lastOcc(const vector<int>& arr, int l, int idx, int target) {
    if (idx == l) {
        return -1;
    }
    int res = lastOcc(arr, l, idx + 1, target);
    if (res == -1) {
        if (arr[idx] == target) {
            return idx;
        } else {
            return -1;
        }
    } else {
        return res;
    }
}

// All occurrences of target (returns vector of indices)
vector<int> AllOcc(const vector<int>& arr, int l, int idx, int target, int fsf) {
    if (idx == l) {
        return vector<int>(fsf); // Create vector with fsf elements
    }

    if (arr[idx] == target) {
        vector<int> res = AllOcc(arr, l, idx + 1, target, fsf + 1);
        res[fsf] = idx;
        return res;
    } else {
        return AllOcc(arr, l, idx + 1, target, fsf);
    }
}

int main() {
    vector<int> a(10);
    
    cout << "Enter array of 10 elements:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    
    int target;
    cout << "Enter target: ";
    cin >> target;
    
    int r1 = firstOcc(a, a.size(), 0, target);
    cout << target << " first occurs at index: " << r1 << endl;
    
    int r2 = lastOcc(a, a.size(), 0, target);
    cout << target << " last occurs at index: " << r2 << endl;
    
    vector<int> r3 = AllOcc(a, a.size(), 0, target, 0);
    cout << "All occurrences of " << target << ": ";
    for (int num : r3) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}