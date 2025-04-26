#include<iostream>
#include<vector>
using namespace std;

/**
  * In each recursive call you are either including the string or not including it so at first you including it then backtracking back and the excluding it. 
  * creates a binary tree of recursion with 2ⁿ leaves (where n = strlen(input)).
  * Time complexity: O(n · 2ⁿ) , O(n) for printing and other for total recursive calls. 
  * Space complexity: 
   - The maximum depth of the recursion is when i reaches the end of the string (n characters long), so the recursion depth is O(n)
   - Recursion Depth: O(n) (max depth of the call stack).
   - Output Storage: O(n) (the output buffer).

  Total Space: O(n).
 */
void subsetsBacktracking(char *input, char *output, int i, int j) {
  
  if(input[i] == '\0') {
    output[j] = '\0';
    if(output[0] == '\0') {
        cout << "NULL" << endl;
    }
    cout << output << endl;
    return;
  }

  output[j] = input[i];
  subsetsBacktracking(input, output, i + 1, j + 1);
  subsetsBacktracking(input, output, i + 1, j);
}

void subsetsBacktrackingV2(char *input, char *output, int i, int j, vector<string> & list) {
  
  if(input[i] == '\0') {
    output[j] = '\0';
    string temp(output);
    list.push_back(temp); 
    return;
  }

  output[j] = input[i];
  subsetsBacktrackingV2(input, output, i + 1, j + 1, list);
  subsetsBacktrackingV2(input, output, i + 1, j, list);
}

bool compare(string s1, string s2) {
    if(s1.length() == s2.length()) {
        return s1 < s2; //if same length then lexicographically
    } else {
        return s1.length() < s2.length(); // if diff size then return smallest string than largest
    }
}
int main() {

    char input[100];
    char output[100];
    cout << "enter string: " << endl;
    cin >> input;
    cout << "subsets..." << endl;
    vector<string> list;

    subsetsBacktrackingV2(input, output, 0, 0, list);
     
    //sort(list.begin(), list.end()); // lexicographically, dictionary ordering
    sort(list.begin(), list.end(), compare);
    cout << "[";
    for(int i=0;i<list.size();i++) {
        cout << list[i];
        if(i != list.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}


