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
     //method 1  recursive
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
 
 //method 2  iterative
 if(root == NULL) return;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* current = stack.top(); stack.pop();
            if(current->right != NULL) stack.push(current->right);
            if(current->left != NULL) stack.push(current->left);
            if(!stack.empty()) {
                current->right = stack.top();// e.g 1->2
            }
            current->left = NULL; //cause we need a right skewed tree
        }
        return;
 
 //method 3 recursive
 if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;    
    }
    private:
    TreeNode* prev = NULL;
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
