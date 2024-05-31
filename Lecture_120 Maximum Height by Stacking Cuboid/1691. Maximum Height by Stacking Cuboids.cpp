class Solution {
public:
    
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;
            
        else
            return false;
    }
    
    int solveTab(int n, vector<vector<int>>& a){
        
        vector<int> CurrRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                
                int take = 0;
                if(prev == -1|| check(a[curr], a[prev])){
                    take = a[curr][2] + nextRow[curr + 1];
                }
                
                int notTake = 0 + nextRow[prev + 1];
                
                CurrRow[prev+1] = max(take, notTake);
            }
            nextRow = CurrRow;
        }
        
        return nextRow[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }
        
        sort(cuboids.begin(), cuboids.end());
        
        return solveTab(cuboids.size(), cuboids);
    }
};