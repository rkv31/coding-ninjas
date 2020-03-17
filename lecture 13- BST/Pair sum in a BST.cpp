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
#include<algorithm>
vector<int> bstToArray(BinaryTreeNode<int> *root)
{
    vector<int> arr;
    if (root == NULL)
        return arr;
    vector<int> leftarr = bstToArray(root->left);
    for (int i = 0; i < leftarr.size(); i++)
    {
        arr.push_back(leftarr[i]);
    }
    arr.push_back(root->data);
    vector<int> rightarr = bstToArray(root->right);
    for (int i = 0; i < rightarr.size(); i++)
    {
        arr.push_back(rightarr[i]);
    }
    return arr;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    vector<int> vc = bstToArray(root);
    int i = 0;
    int j = vc.size()-1;
    while( i < j )
    {
        if(vc[i] + vc[j] == s)
        {
            cout<<vc[i]<<" "<<vc[j]<<endl;
            i++;
            j--;
        }
            
        else if (vc[i] + vc[j] < s)
            i++;
        else if (vc[i] + vc[j] > s)
            j--;
    }
}
