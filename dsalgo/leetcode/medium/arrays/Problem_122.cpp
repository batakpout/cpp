/**
Valley Peak Approach
 * Best time to buy and sell stock
 * with many transactions
 * O(n) time complexity
 */
#include<iostream>
using namespace std;

int buyAndSellStock(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i=1;i<n;i++) {
            if(prices[i] > prices[i-1]) {
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
}

int main() {
    int size;
    cout << "enter array size:";
    cin >> size;
    vector<int>prices(size);
    cout << "enter " << size << " array elements: \n";
    for(int i=0;i<size;i++) {
        cin >> prices[i];
    }

    int res = buyAndSellStock(prices);
    cout << "Profit: " << res << endl;
    return 0;
}
