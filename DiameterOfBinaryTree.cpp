/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
     *We can solve this problem with two different cases:

If the longest path will include the root node, then the longest path must be the depth(root->right) + depth (root->left)
If the longest path does not include the root node, this problem is divided into 2 sub-problem: set left child and right child as the new root separately, and repeat step1.
We could get the solution by returning the max path of 1 and 2.

*/
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = depth(root->left) + depth(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        
    }
    
    int depth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};