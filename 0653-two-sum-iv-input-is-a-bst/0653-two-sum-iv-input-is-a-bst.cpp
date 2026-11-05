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
 */class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        unordered_set<int> st;

        return solve(root, k, st);
    }

    bool solve(TreeNode* root, int k, unordered_set<int>& st) {

        // If node is empty
        if(root == NULL) {
            return false;
        }

        // Find the number needed to make sum k
        int required = k - root->val;

        // Check if required number already exists
        if(st.find(required) != st.end()) {
            return true;
        }

        // Store current node's value
        st.insert(root->val);

        // Search left and right subtree
        return solve(root->left, k, st) ||
               solve(root->right, k, st);
    }
};