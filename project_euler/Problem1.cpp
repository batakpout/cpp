/**

First, p = (n - 1) // k calculates how many multiples of k are below n:

Example: If n = 10 and k = 3
p = (10 - 1) // 3 = 3
This means there are 3 multiples of 3 below 10 (3, 6, 9), same for 5 will be 1


The formula k * (p * (p + 1)) // 2 is a mathematical trick to sum consecutive integers:

It's equivalent to the sum of numbers: 1 + 2 + 3 + ... + p
This sum can be calculated as: p * (p + 1) / 2
Multiplying by k gives us the sum of multiples of k

---to find numbers from 1 to 100 divisible by 3 ---
we can use a(n) = a1 + (n-1) d
for 3, a(n) = 99, a1 = 3 and d = 3, we get n
--> do for other number also and then apply inclusion-exclusion principle
 */

#include <iostream>
using namespace std;

// Function to calculate sum of multiples of k below n
long long sum_multiples(long long k, long long n) {
    long long m = (n - 1) / k;
    return k * m * (m + 1) / 2;
}

// Function to calculate sum of multiples of 3 or 5 below n
long long sum_3_or_5(long long n) {
    return sum_multiples(3, n) + sum_multiples(5, n) - sum_multiples(15, n);
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        
        long long result = sum_3_or_5(n);
        cout << result << endl;
    }
    
    return 0;
}
