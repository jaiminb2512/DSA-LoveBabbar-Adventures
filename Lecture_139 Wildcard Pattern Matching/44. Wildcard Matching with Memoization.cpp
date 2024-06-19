class Solution {
public:
    
    bool solve(string& str, string& p, int i, int j, vector< vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if( dp[i][j] != -1) return  dp[i][j];
        
        if(str[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(str, p, i-1, j-1,dp);
        
        else if(p[j] == '*')
            return dp[i][j] = (solve(str, p, i-1, j,dp) || solve(str, p, i, j-1,dp));
        
        else 
            return false;
    }
    
    bool isMatch(string s, string p) {
        vector< vector<int> > dp(s.length(), vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1, p.length()-1,dp);
    }
};