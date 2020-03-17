// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<vector>
void helper(BinaryTreeNode<int> *root, vector<int> arr, int k)
{
    if (root == NULL || root->data > k)
        return;
    arr.push_back(root->data);
    if (k - root->data == 0)
    {
        for (int i=0; i < arr.size(); i++ )
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    helper(root->left, arr, k - root->data);
    helper(root->right, arr, k - root->data);
    
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> arr;
    helper(root, arr, k);
}
