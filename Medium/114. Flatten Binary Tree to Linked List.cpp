/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* temp, *node;
        if(root){                 //Move the left node to the right node
            temp = root->right;
            root->right = root->left;
            root->left = NULL;
            node = root;
        }
        while(node->right){      //Move to the end of the prev left node which is the new right node
            node = node->right;
        }
        node->right = temp;     //Append the right node to its end
        flatten(root->right);
    }
};




/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
          
*/
