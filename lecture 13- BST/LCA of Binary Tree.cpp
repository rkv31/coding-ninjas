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
BinaryTreeNode<int> *findLCAUtil(BinaryTreeNode<int>* root, int n1, int n2, bool &v1, bool &v2)    //This is the prominent func.
{ 
    if (root == NULL) return NULL; 
  
    if (root->data == n1) 
    { 
        v1 = true; 
        return root; 
    } 
    if (root->data == n2) 
    { 
        v2 = true; 
        return root; 
    } 
  
    BinaryTreeNode<int> *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2); 
    BinaryTreeNode<int> *right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 
  
    if (left_lca && right_lca)  return root; 
  
    return (left_lca != NULL)? left_lca: right_lca; 
} 
  
bool find(BinaryTreeNode<int> *root, int k)             //func. to find if nodes are present or not
{ 
    if (root == NULL) 
        return false; 

    if (root->data == k || find(root->left, k) ||  find(root->right, k)) 
        return true; 
  
    return false; 
} 
  
BinaryTreeNode<int> *findLCA(BinaryTreeNode<int> *root, int n1, int n2) 
{ 
    bool v1 = false, v2 = false; 
  
    BinaryTreeNode<int> *lca = findLCAUtil(root, n1, n2, v1, v2); 
  
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))         //evaluates true only if both nodes are present else false
        return lca; 

    return NULL; 
}

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    // Write your code here
    BinaryTreeNode<int> *lcaRoot = findLCA(root, val1, val2);
    if (lcaRoot == NULL)
        return -1;
    return lcaRoot->data;
}