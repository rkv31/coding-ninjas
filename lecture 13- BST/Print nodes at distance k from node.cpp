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
// void printkdistanceNodeDown(BinaryTreeNode<int> *root, int k)
// {
//     if (root == NULL || k < 0)
//         return;
//     if (k == 0)
//     {
//         cout<<root->data<<endl;
//         return;
//     }
//     printkdistanceNodeDown(root->left, k-1);
//     printkdistanceNodeDown(root->right, k-1);
// }
// int nodesAncestor(BinaryTreeNode<int> *root, int node, int k)
// {
//     if (root == NULL)
//         return -1;
//     if (root->data == node)
//     {
//         printkdistanceNodeDown(root, k); 
//         return 0;
//     }
//     int dl = nodesAncestor(root->left, node, k);
//     if ( dl != -1 )
//     {
//         if (dl + 1 == k) 
//             cout << root->data << endl; 
  
//          // Else go to right subtree and print all k-dl-2 distant nodes 
//          // Note that the right child is 2 edges away from left child 
//          else
//             printkdistanceNodeDown(root->right, k-dl-2); 
  
//          return 1 + dl;
//     }
    
//     int dr = nodesAncestor(root->right, node, k); 
//     if (dr != -1) 
//     { 
//          if (dr + 1 == k) 
//             cout << root->data << endl; 
//          else
//             printkdistanceNodeDown(root->left, k-dr-2); 
//          return 1 + dr; 
//     } 
  
//     // If target was neither present in left nor in right subtree 
//     return -1; 
// }


// void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
//     // Write your code here
//     int ans = nodesAncestor(root, node, k);
// }
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
BinaryTreeNode<int> *findNode(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    BinaryTreeNode<int> *l = findNode(root->left, data);
    if ( l == NULL)
        return findNode(root->right, data);
    else
        return l;
    
    
}

void populateNodeToParentMap(unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *>*hashmap, BinaryTreeNode<int> *root, BinaryTreeNode<int> *parent) {

  /*
    We can't add a null node to the map, return
  */
    if (root == NULL) {
        return;
  }

  /*
    Map the node to its parent
  */
    hashmap->insert(make_pair(root, parent)); 
  /*
    Go left and after that go right. The call that we make next
    will have what we call 'root' now as the 'parent' value so
    we can do the mapping in THAT call stack frame...and so on
    and so on...
  */
    populateNodeToParentMap(hashmap, root->left, root);
    populateNodeToParentMap(hashmap, root->right, root);
}


void helper(BinaryTreeNode<int> *root, BinaryTreeNode<int> *targetNode, int k)
{
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *>hashmap;
    populateNodeToParentMap(&hashmap, root, NULL);
    
    queue<BinaryTreeNode<int>*> q;
    q.push(targetNode);
    
    unordered_set<BinaryTreeNode<int> *>seen;
    seen.insert(targetNode);
    int currentLayer = 0;
    
    while ( !q.empty() )
    {
        if (currentLayer == k)
        {
            cout<<q.front()->data<<endl;
            q.pop();
        }
        else
        {
            int layerSize = q.size();
            
            for (int i = 0; i < layerSize; i++) 
            {

          /*
            Pull a node from the search queue, we are going to basically
            use our current layer to populate the next layer of nodes
            that we need to search in the next while loop iteration
          */
                BinaryTreeNode<int> *currentNode = q.front();
                q.pop();
                /*
                Has left been touched before?
                No?
                  1.) Add it to the seen hashtable
                  2.) Add it to the search queue
                 */
                if (currentNode->left != NULL && (seen.find(currentNode->left) == seen.end()) ) 
                {
                    seen.insert(currentNode->left);
                    q.push(currentNode->left);
                }

                /*
                    Has right been touched before?
                    No?
                    1.) Add it to the seen hashtable
                    2.) Add it to the search queue
                  */
                if (currentNode->right != NULL && (seen.find(currentNode->right) == seen.end()) ) 
                {
                    seen.insert(currentNode->right);
                    q.push(currentNode->right);
                }
                
                /*
                Has this node's parent been touched before?
                No?
                  1.) Add it to the seen hashtable
                  2.) Add it to the search queue
                */
                BinaryTreeNode<int> *parentOfCurrentNode = hashmap[currentNode];
                if (parentOfCurrentNode != NULL && (seen.find(parentOfCurrentNode) == seen.end()) ) 
                {
                    seen.insert(parentOfCurrentNode);
                    q.push(parentOfCurrentNode);
                }

            }
            currentLayer++;
        }
    }
}




void nodesAtDistanceK(BinaryTreeNode<int> *root, int data, int k) {
    // Write your code here
    BinaryTreeNode<int> *targetNode = findNode(root, data);
    helper(root, targetNode, k);
    
}

