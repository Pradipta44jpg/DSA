#include <stdio.h>
#include <stdlib.h>

// Define TreeNode struct first
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// DFS helper function
void dfs(struct TreeNode *root, int level, int* res, int* size){
    if(root == NULL) return;

    if(level == *size){
        res[*size] = root->val;
        (*size)++;
    }

    dfs(root->right, level + 1, res, size);
    dfs(root->left, level + 1, res, size);
}

// Main function
int* rightSideView(struct TreeNode* root, int* returnSize){
    int *res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    dfs(root, 0, res, returnSize);

    return res;
}

// Optional: main function to test locally
int main() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};

    n1.left = &n2; n1.right = &n3;
    n2.right = &n5;
    n3.right = &n4;

    int size;
    int* res = rightSideView(&n1, &size);

    printf("Right side view: ");
    for(int i=0; i<size; i++){
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}
