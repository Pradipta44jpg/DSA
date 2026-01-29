int dfs(struct TreeNode* root, int current) {
    if (root == NULL)
        return 0;

    current = current * 10 + root->val;

    // If leaf node, return the formed number
    if (root->left == NULL && root->right == NULL)
        return current;

    // Otherwise, sum from left and right subtrees
    return dfs(root->left, current) + dfs(root->right, current);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}
