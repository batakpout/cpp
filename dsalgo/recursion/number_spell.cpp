#include<iostream>

using namespace std;

  const vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

/*
The time complexity of the function numberSpell(int n) is O(d), where d is the number of digits in the number n

Space complexity: O(d) due to recursion stack
*/
void numberSpell(int n) {
  
    if(n == 0) {
        return;
    }
    int rem = n % 10;
    numberSpell(n / 10);
    cout << v[rem] << " ";
}

int main() {

    cout << "Enter a number to spell: " << endl;
    int n;
    cin >> n;
    numberSpell(n);
    cout << endl;
    return 0;
}