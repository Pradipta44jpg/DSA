* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #include <limits.h>

void inorder(struct TreeNode* root, int *arr, int *index) {
    if (root == NULL) return;

    inorder(root->left, arr, index);
    arr[*index] = root->val;
    (*index)++;
    inorder(root->right, arr, index);
}

int getMinimumDifference(struct TreeNode* root) {

    int arr[10000];
    int index = 0;

    inorder(root, arr, &index);


    int min = INT_MAX;

    for (int i = 1; i < index; i++) {
        int diff = arr[i] - arr[i-1];
        if (diff < min)
            min = diff;
    }

    return min;
}
