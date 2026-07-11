class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base Case
        if(root == NULL || root == p || root == q)
            return root;

        // Search left subtree
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);

        // Search right subtree
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // If both sides returned a node, current node is LCA
        if(leftAns != NULL && rightAns != NULL)
            return root;

        // If only left subtree has one of the nodes
        if(leftAns != NULL)
            return leftAns;

        // Otherwise return right subtree result
        return rightAns;
    }
};