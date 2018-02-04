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
    ����Ŀ�еĵڶ��������п��Կ��������������Ǵ�Ҷ��㿪ʼ�ģ��м�ĳ�����ֵĲ���������������ô����ת��һ��˼·���ǲ��Ǵ�s��ĳ����㿪ʼ����t�����нṹ��һ������ô�����ת�������ж��������Ƿ���ͬ���ȴ�s�ĸ���㿪ʼ����t�Ƚϣ������������ȫ��ͬ����ô����true������ͷֱ��s�����ӽ������ӽ����õݹ��ٴ����ж��Ƿ���ͬ��ֻҪ��һ������true�ˣ��ͱ�ʾ�����ҵõ���
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