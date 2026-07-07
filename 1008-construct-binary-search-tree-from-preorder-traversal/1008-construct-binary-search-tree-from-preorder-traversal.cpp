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

    TreeNode* solve(vector<int>& preorder,
                    int& index,
                    int minVal,
                    int maxVal)
    {
        // Base case
        if(index == preorder.size())
            return NULL;

        // Current value doesn't belong to this subtree
        if(preorder[index] < minVal || preorder[index] > maxVal)
            return NULL;

        // Create root
        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        // Build left subtree
        root->left = solve(preorder, index, minVal, root->val);

        // Build right subtree
        root->right = solve(preorder, index, root->val, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int index = 0;

        return solve(preorder, index, INT_MIN, INT_MAX);
    }
};