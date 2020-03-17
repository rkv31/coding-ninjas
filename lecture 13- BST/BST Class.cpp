/**************
 
 * Following is BinaryTreeNode class -
 
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
 
 * Foloowing is main function which we are using internally

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
*******************/


class BST {
	// Complete this class
    BinaryTreeNode<int> *root;
    public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    private:
    
    bool hasData(BinaryTreeNode<int>* node, int data)        //searching
    {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        else if (node->data > data)
            return hasData(node->left, data);
        else
            return hasData(node->right, data);
    }
    
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data)            //inserting
    {
        if (node == NULL)
        {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (node->data > data)
        {
            node->left = insert(node->left, data);
        }
        if (node->data <= data)
        {
            node->right = insert(node->right, data);
        }
        return node;
        
    }
    BinaryTreeNode<int>* minValueNode(BinaryTreeNode<int>* node)        //finding inorder successor in right sub-tree
    {
        BinaryTreeNode<int>* curr = node;
        while (curr && curr->left != NULL)
            curr = curr->left;
        return curr;
    }
    
    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* node, int data)        //deleting
    {
        if (node == NULL)
            return NULL;
        if (node->data == data)
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int>* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteData(node->right, temp->data);
            }
        }
        if (node->data > data)
            node->left = deleteData(node->left, data);
        else
            node->right = deleteData(node->right, data);
        return node;
        
    }
    void printTree(BinaryTreeNode<int>* node)                //printing
    {
        if (node == NULL)
            return;
        cout<<node->data<<":";
        if (node->left != NULL)
            cout<<"L:"<<node->left->data<<",";
        if (node->right != NULL)
            cout<<"R:"<<node->right->data;
        cout<<endl;
        printTree(node->left);
        printTree(node->right);
    }
    
    public:
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void insert(int input)
    {
        this->root = insert(root, input);
    }
    void deleteData(int input)
    {
        this->root = deleteData(root, input);
    }
    void printTree()
    {
        printTree(root);
    }
};
