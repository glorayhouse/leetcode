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
private:
    int cur_sum = 0;

public:
    void travel(TreeNode* root) {
        if (!root) return;
        //遍历顺序，右根左，反向计算累加和sum，同时更新结点值
        if (root->right) travel(root->right);
        cur_sum = cur_sum + root->val;
        root->val = cur_sum;
        if(root->left) travel(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};