#include<iostream>
using namespace std;
/**
 use euler tree to understand the flow
 TC: O(2^n), binary recursive pattern, where each level of recursion doubles the number of calls.
 SC: O(n):
  due to the sequential nature of depth-first recursion, the right-side recursive calls only begin after the left-side ones finish, meaning the stack does not simultaneously hold all these calls. This is why the space complexity is O(n)
 */
void zig_zag(int n) {

     if(n == 0) return;
     else {
        cout << "Pre: " << n << endl;
        zig_zag(n-1);
        cout << "In: " << n << endl;
        zig_zag(n-1);
        cout << "Post: " << n << endl;
     }
}

int main() {

    int n;
    cout << endl;
    cin >> n;
    zig_zag(n);

    return 0;
}