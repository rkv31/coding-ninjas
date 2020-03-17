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
int helper(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
        return sum;
    int preSum = helper(root->right, sum);
    root->data = root->data + preSum;
    sum = root->data;
    int leftSum = helper(root->left, sum);
    return leftSum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int ans = helper(root, 0);
}
