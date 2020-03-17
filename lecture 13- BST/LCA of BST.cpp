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

int lcaInBST(BinaryTreeNode<int>* root , int n1 , int n2){
    // Write your code here
    while (root != NULL) 
    { 
        if (root->data > n1 && root->data > n2) 
           root = root->left; 
        
        else if (root->data < n1 && root->data < n2) 
           root = root->right; 
  
        else break; 
    }
    if (root == NULL)
        return -1;
    return root->data;
}
