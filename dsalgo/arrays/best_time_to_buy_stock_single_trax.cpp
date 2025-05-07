/**
 * Best time to buy and sell stock
 * with one transaction
 * O(n) time
 * Input: prices = [7,1,5,3,6,4]
   Output: 5
 */
#include<iostream>
using namespace std;

int buyAndSellStock(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxProfit = 0;
        int cost;
        for(int i=0;i<n;i++) {
            cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(prices[i], mini);

        }
        return maxProfit;
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