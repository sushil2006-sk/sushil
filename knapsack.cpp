#include <iostream>
using namespace std;

int main() {
    int n = 3;                 // number of items
    int W = 50;                // capacity

    int wt[] = {10, 20, 30};   // weights
    int val[] = {60, 100, 120}; // values

    int dp[4][51];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum value: " << dp[n][W];

    return 0;
}