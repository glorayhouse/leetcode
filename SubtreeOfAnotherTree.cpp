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
    /*
    从题目中的第二个例子中可以看出，子树必须是从叶结点开始的，中间某个部分的不能算是子树，那么我们转换一下思路，是不是从s的某个结点开始，跟t的所有结构都一样，那么问题就转换成了判断两棵树是否相同。先从s的根结点开始，跟t比较，如果两棵树完全相同，那么返回true，否则就分别对s的左子结点和右子结点调用递归再次来判断是否相同，只要有一个返回true了，就表示可以找得到。
    */
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};