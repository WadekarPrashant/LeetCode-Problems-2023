class Solution {
public:
    TreeNode* prev;
    int ans;
    void inorder(TreeNode* root)
    {
        if (root == NULL)
        return;
        inorder(root->left);
        if (prev != NULL)
        {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        inorder(root->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        ans = 1e5;
        prev = NULL;
        inorder(root);
        return ans;
    }
};
