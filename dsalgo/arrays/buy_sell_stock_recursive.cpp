#include<iostream>
using namespace std;

/**
Time Complexity: O(2 ^n)
Space Complexity: O(n) (due to recursion stack).
 for O(n) find in folder leetcode/medium/Problem 122
 */

int buyAndSellStock(int prices [], int start, int end) {
    if(end<=start) return 0;
    int maxProfit = 0;

    for(int i=start;i<=end;i++) {
        for(int j=i+1;j<=end;j++) {
            if(prices[j] > prices[i]) {
                int currProfit = prices[j] - prices[i] + 
                    buyAndSellStock(prices, start, i-1) + buyAndSellStock(prices, j+1, end);
                maxProfit = max(currProfit, maxProfit);
            }
        }
    }
    return maxProfit;
}

int main() {
    int size;
    cout << "enter array size:";
    cin >> size;
    int prices[size];
    cout << "enter " << size << " array elements: \n";
    for(int i=0;i<size;i++) {
        cin >> prices[i];
    }
    int res = buyAndSellStock(prices, 0, size-1);
    cout << "Profit: " << res << endl;
    return 0;
}