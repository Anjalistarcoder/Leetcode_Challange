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

    struct Info
    {
        bool isBST;
        int mini;
        int maxi;
        int sum;
    };

    int ans = 0;

    Info solve(TreeNode* root)
    {
        // Base case
        if(root == NULL)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        // Check if current subtree is BST
        if(left.isBST && right.isBST &&
           root->val > left.maxi &&
           root->val < right.mini)
        {
            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.mini = min(root->val, left.mini);
            curr.maxi = max(root->val, right.maxi);

            ans = max(ans, curr.sum);
        }
        else
        {
            curr.isBST = false;
            curr.sum = 0;
            curr.mini = INT_MIN;
            curr.maxi = INT_MAX;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root)
    {
        solve(root);
        return ans;
    }
};