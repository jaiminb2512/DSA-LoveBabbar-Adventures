//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* start;
        unordered_map<Node*, Node*> parent;
        
        queue<Node*> Q;
        Q.push(root);
        
        while(!Q.empty())
        {
            int sz = Q.size();
            
            while(sz--)
            {
                Node* cur = Q.front();
                Q.pop();
                
                if(cur->data == target)
                start = cur;
                
                if(cur->left)
                {
                    Q.push(cur->left);
                    parent[cur->left] = cur;
                }
                
                if(cur->right)
                {
                    Q.push(cur->right);
                    parent[cur->right] = cur;
                }
            }
        }
        
        Q.push(start);
        
        set<int> burned;
        
        int t = -1;
        
        while(!Q.empty())
        {
            int sz = Q.size();
            
            while(sz--)
            {
                Node* cur = Q.front();
                Q.pop();
                
                burned.insert(cur->data);
                
                if(cur != root and burned.find(parent[cur]->data) == burned.end())
                    Q.push(parent[cur]);
                
                if(cur->left and burned.find(cur->left->data) == burned.end())
                    Q.push(cur->left);
                
                if(cur->right and burned.find(cur->right->data) == burned.end())
                    Q.push(cur->right);
            }
            
            t++;
        }
        
        return t;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends