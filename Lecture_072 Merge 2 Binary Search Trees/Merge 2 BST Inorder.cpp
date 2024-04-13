/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void inOrder(TreeNode* root, vector<int> &ans){
    if(root == NULL)
        return;

    inOrder(root -> left, ans);
    ans.push_back(root -> data);
    inOrder(root -> right, ans);
}

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2){
    if(arr1.size() == 0 || arr2.size() == 0){
        return (arr1.size()) ? arr1 : arr2;
    }

    int i=0, j=0;
    vector<int> solution;

    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] < arr2[j]){
            solution.push_back(arr1[i++]);
        }
        else{
            solution.push_back(arr2[j++]);
        }
    }

    while(i<arr1.size()){
        solution.push_back(arr1[i++]);
    }

    while(j<arr2.size()){
        solution.push_back(arr2[j++]);
    }

    return solution;
}

TreeNode* createBST(vector<int> &arr, int start, int end){
    if(start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2){
    vector<int> arr1;
    vector<int> arr2;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> resultArray = mergeArrays(arr1, arr2);

    return resultArray;
}