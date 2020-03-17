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
class pairReturn{
    public:
    int min;
    int max;
    bool isBST;
    int height;
};
pairReturn helper(BinaryTreeNode<int> *root)
{
    pairReturn p;
    if (root->left == NULL && root->right == NULL)
    {
        p.min = root->data;
        p.max = root->data;
        p.isBST = true;
        p.height = 1;
        return p;
    }
    pairReturn left = helper(root->left);
    pairReturn right = helper(root->right);
    if ( (left.isBST == true && right.isBST == true) && (left.max < root->data && root->data <= right.min) )
    {
        p.isBST = true;
        p.min = left.min;
        p.max = right.max;
        p.height = 1 + max(left.height, right.height);
    }
    else
    {
        p.isBST = false;
        p.height = max(left.height, right.height);
        p.min = left.min;
        p.max = right.max;
    }
    return p;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    pairReturn ans = helper(root);
    return ans.height;
}
