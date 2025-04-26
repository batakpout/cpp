#include<iostream>

using namespace std;

//assuming 4*N board with  4*1 tiles or 1*4
int noOfWays(int n) {

    if(n<=3) {
        return 1;
    }
    return noOfWays(n-1) + noOfWays(n-4);
}

//assuming M * N board with tiles 1 * M
int noOfWaysGeneric(int n, int m) {

    if(n < m) {
        return 1;
    }
    return noOfWaysGeneric(n-1, m) + noOfWaysGeneric(n-m, m);
}
int main() {

    cout << "enter board width: \n";
    int n;
    cin >> n;
    cout << "No of ways to place tiles: " << noOfWays(n) << endl;
    cout << "enter title dimensions: ";
    int m;
    cin >> m;
    cout << "No of ways to place tiles: " << noOfWaysGeneric(n, m) << endl;
    return 0;
}