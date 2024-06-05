//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int index, int diff, int A[]){
        if(index < 0) return 0;
        
        int ans = 0;
        for(int j=index-1; j>=0; j--){
            if(A[index]-A[j] == diff){
                ans = max(ans, 1 + solve(j, diff, A));
            }
        }
        
        return ans;
    }

    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2) return n;
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, 2 + solve(i, A[j]-A[i], A));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends