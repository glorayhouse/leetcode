// 124. 二叉树中的最大路径和
// 给定一个非空二叉树，返回其最大路径和。

// 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

// 示例 1:

// 输入: [1,2,3]

//        1
//       / \
//      2   3

// 输出: 6
// 示例 2:

// 输入: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// 输出: 42

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 思路：二叉树节点特点，被父节点连接，连接左右两个子节点；路径的特点，只有来和去两个方向
 */
class Solution {
public:
    int maxPath(TreeNode* root, int& val) {
        //计算一个节点通往下方的最大路径和
        if (root == nullptr) return 0;
        int left = max(0, maxPath(root->left, val));
        int right = max(0, maxPath(root->right, val));
        int ret = max(left, right) + root->val;
        int lmr = left + root->val + right;
        //全局最大和可能有三种情况：自己，左中右和，自己+最大的子节点
        val = max(val, max(lmr, ret));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        //全局最大和，可能有负数
        int val = std::numeric_limits<int>::lowest();
        maxPath(root, val);
        return val;
    }
};

