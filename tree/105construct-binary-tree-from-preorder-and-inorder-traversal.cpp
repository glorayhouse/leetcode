// 105. 从前序与中序遍历序列构造二叉树
// 根据一棵树的前序遍历与中序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 解法一：时间复杂度o(n*n)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        
    }

    TreeNode* helper(vector<int>& preorder, int preLeft, int preRight,
    vector<int>& inorder, int inLeft, int inRight) {
        if ((preLeft > preRight) || (inLeft > inRight)) return nullptr;
        auto root = new TreeNode(preorder[preLeft]);
        int mid = inLeft;
        while (inorder[mid] != preorder[preLeft]) ++mid;
        root->left = helper(preorder, preLeft + 1, mid - inLeft + preLeft, inorder, inLeft, mid -1);
        root->right = helper(preorder, mid - inLeft + preLeft + 1, preRight, inorder, mid + 1, inRight);
        return root;
    }
};

/**
// 解法一：时间复杂度o(n)
题设中说树中没有重复的元素，因此可以将中序遍历的值和下标index用一个map来保存，节省找中序的root节点的时间
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in_size = inorder.size();
        std::map<int, int> in_map;
        for (int i = 0; i < in_size; i++) {
            in_map[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, in_map);
        
    }

    TreeNode* helper(vector<int>& preorder, int pre_left, int pre_right,
    vector<int>& inorder, int in_left, int in_right, std::map<int, int>& in_map) {
        if ((pre_left > pre_right) || (in_left > in_right)) return nullptr;
        auto root = new TreeNode(preorder[pre_left]);
        int mid = in_map[root->val];
        root->left = helper(preorder, pre_left + 1, mid - in_left + pre_left, inorder, in_left, mid -1, in_map);
        root->right = helper(preorder, mid - in_left + pre_left + 1, pre_right, inorder, mid + 1, in_right, in_map);
        return root;
    }
};