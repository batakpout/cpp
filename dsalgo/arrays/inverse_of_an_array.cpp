#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//TC: O(N), SC: O(N)
vector<int> inverse(const vector<int>& a) {
    vector<int> inv(a.size());

    for (int i = 0; i < a.size(); ++i) {
        int v = a[i];
        inv[v] = i;
    }

    return inv;
}


int main() {

  vector<int>v = {4,0,2,1,3};
  vector<int> r = inverse(v);
  for(int i=0;i<5;i++) {
    cout << r[i] << " ";
  }
  cout << endl;
    return 0;
}