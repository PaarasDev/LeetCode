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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int r = getD(root->left,true) + 1;
        int l = getD(root->right,false) + 1;
        if(r==l) return (1 << r) - 1;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
    int getD(TreeNode* root, bool dir){
        int d = 0;
        while(root){
            root = dir ? root->left : root->right;
            d++;
        }
        return d;
    }
};