/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void inorder(struct TreeNode* root, int* arr, int* size) {
    if (!root) return;
    inorder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inorder(root->right, arr, size);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int arr[10000];
    int size = 0;
    inorder(root, arr, &size);

    int* result = (int*)malloc(sizeof(int) * size);
    int resSize = 0;

    int count = 1;
    int maxcount = 1;

    for (int i = 1; i <= size; i++) {
        if (i < size && arr[i] == arr[i - 1]) {
            count++;
        } else {
            if (count > maxcount) {
                maxcount = count;
                resSize = 0;
                result[resSize++] = arr[i - 1];
            } else if (count == maxcount) {
                result[resSize++] = arr[i - 1];
            }
            count = 1;
        }
    }

    *returnSize = resSize;
    return result;
}
