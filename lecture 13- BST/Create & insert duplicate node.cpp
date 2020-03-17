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

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if (root == NULL)
        return;
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    newNode->left = root->left;
    root->left = newNode;
    insertDuplicateNode(root->left->left);
    insertDuplicateNode(root->right);
}
