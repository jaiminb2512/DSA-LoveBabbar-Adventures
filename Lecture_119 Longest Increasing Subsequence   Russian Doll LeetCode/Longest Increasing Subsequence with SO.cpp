//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int solveSO(int n, int a[]){
        
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                
                int take = 0;
                if(prev == -1 || a[curr] > a[prev])
                    take = 1 + nextRow[curr+1];
                    
                int notTake = nextRow[prev+1];
                
                currRow[prev+1] = max(take, notTake);
            }
            
            nextRow = currRow;
        }
            
        return nextRow[0];
    }
    
    
    int longestSubsequence(int n, int a[])
    {
        return solveSO(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends