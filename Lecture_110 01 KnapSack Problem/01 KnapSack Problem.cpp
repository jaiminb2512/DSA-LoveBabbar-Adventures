#include <bits/stdc++.h> 

int solve(vector<int>& weight, vector<int>& value, int n, int capacity){
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    return solve(weight, value, n, maxWeight);
}
