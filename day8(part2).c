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
void preorder(struct TreeNode *root,int *arr,int *index){
    if(root==NULL) return;
    arr[*index]=root->val;
    (*index)++;
    preorder(root->left,arr,index);
    preorder(root->right,arr,index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
      int* arr = (int*)malloc(100 * sizeof(int)); 
    *returnSize = 0;
    preorder(root,arr,returnSize);
    return arr;
   }