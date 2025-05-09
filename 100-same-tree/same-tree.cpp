class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, they are same
        if (!p && !q) return true;
        // If one is null and other is not, they are different
        if (!p || !q) return false;
        // If values are different
        if (p->val != q->val) return false;
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
