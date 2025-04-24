#include<iostream>
using namespace std;

//TC: O(n)
//SC: O(n) maximum depth of recursion occurs when the function is called with the initial value of num down to 0
void printDecreasingIncreasing(int num) {
    if(num == 0) return;
    cout << num << " "; 
    printDecreasingIncreasing(num - 1);
    cout << num << " ";

}
int main() {

    printDecreasingIncreasing(6);
    return 0;
}