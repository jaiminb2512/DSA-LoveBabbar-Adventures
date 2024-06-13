class Solution {
public:
    
    int solve(int index, int operationNo, int k, vector<int>& prices){ 
        
        if(index == prices.size() || operationNo == 2 * k) return 0;
        int profit = 0;
        
        if(operationNo % 2 == 0){
            int buyKaro = -prices[index] + solve(index + 1, operationNo + 1, k, prices);
            int skipKaro = solve(index + 1, operationNo, k, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solve(index + 1, operationNo + 1, k, prices);
            int skipKaro = solve(index + 1, operationNo, k, prices);
            profit = max(sellKaro, skipKaro);
        }
         
         return profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
       return solve(0, 0, k, prices);
    }
};
