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
    bool f(TreeNode* r1,TreeNode* r2){
        if (r1==NULL && r2==NULL) return true;
        if (r1==NULL || r2==NULL) return false;
        int a=r1->val;
        int b=r2->val;
        if (a!=b) return false;
        return f(r1->left,r2->right) && f(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return f(root->left,root->right);
        
    }
};