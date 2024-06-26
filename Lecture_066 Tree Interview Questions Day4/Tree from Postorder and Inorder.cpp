//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

int search(int arr[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

Node* buildTreeUtil(int in[], int post[], int inStart, int inEnd, int &postIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* root = new Node(post[postIndex--]);

    if (inStart == inEnd)
        return root;

    int inIndex = search(in, inStart, inEnd, root->data);

    root->right = buildTreeUtil(in, post, inIndex + 1, inEnd, postIndex);
    root->left = buildTreeUtil(in, post, inStart, inIndex - 1, postIndex);

    return root;
}

Node* buildTree(int in[], int post[], int n) {
    int postIndex = n - 1;
    return buildTreeUtil(in, post, 0, n - 1, postIndex);
}
