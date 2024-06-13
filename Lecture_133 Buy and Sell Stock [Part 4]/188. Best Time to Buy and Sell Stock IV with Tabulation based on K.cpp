class Solution {
public:
       
    int solve(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int index=n-1; index >= 0; index--){
            for(int operationNo=1; operationNo <= 2*k; operationNo++){
                
                int profit = 0;
                if(operationNo % 2 == 0){
                    int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                    int skipKaro = dp[index+1][operationNo];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] + dp[index+1][operationNo+1];
                    int skipKaro = dp[index+1][operationNo];
                    profit = max(sellKaro, skipKaro);
                }
                
                dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        return solve(k, prices);
    }
};
