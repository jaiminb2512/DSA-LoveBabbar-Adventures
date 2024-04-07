//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    Node* buildTreeUtil(int in[], int pre[], int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) {
            return NULL;
        }

        Node* root = new Node(pre[preIndex++]);

        int inIndex;
        for (int i = inStart; i <= inEnd; i++) {
            if (in[i] == root->data) {
                inIndex = i;
                break;
            }
        }

        root->left = buildTreeUtil(in, pre, inStart, inIndex - 1, preIndex);
        root->right = buildTreeUtil(in, pre, inIndex + 1, inEnd, preIndex);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        int preIndex = 0;
        return buildTreeUtil(in, pre, 0, n - 1, preIndex);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends