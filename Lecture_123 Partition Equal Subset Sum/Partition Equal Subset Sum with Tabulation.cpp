//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool solve(int N, int arr[], int total){
        
        vector<vector<int> > dp(N+1, vector<int>(total+1, 0));
        
        for(int i=0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= total/2; target++){
                
                bool incl = 0;
                if(target - arr[index] >= 0)
                    incl = dp[index+1][target - arr[index]];
                    
                bool excl = dp[index+1][target];
                
                dp[index][target] = incl or excl;
            }
        }
        return dp[0][total/2];
    }

    int equalPartition(int N, int arr[])
    {
       int total = 0;
       for(int i = 0; i<N; i++){
           total += arr[i];
       }
       
       if(total & 1){
           return 0;
       }
       
       return solve(N, arr, total);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends