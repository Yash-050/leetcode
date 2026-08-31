class Solution {
    TreeNode* curr;

public:
    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        curr->right = root;
        root->left = nullptr;
        curr = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        curr = dummy;

        inorder(root);

        return dummy->right;
    }
};