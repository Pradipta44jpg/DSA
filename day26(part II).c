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
void dfs(struct TreeNode *root, int *path, int pathlen,char **result1, int *returnSize)
{
    if(root == NULL)
    return ;
    path[pathlen++]=root->val;
    if(root->left==NULL && root->right== NULL){
        char *str=(char *)malloc(100* sizeof(char));
        int pos=0;
        for(int i=0;i<pathlen;i++){
            pos+=sprintf(str+pos,"%d",path[i]);
        if(i<pathlen-1)
        pos+=sprintf(str+pos,"->");
    }
    result1[*returnSize]=str;
    (*returnSize)++;
    return;
    }
    dfs(root->left,path,pathlen,result1,returnSize);
    dfs(root->right,path,pathlen,result1,returnSize);
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
   char** result1 = (char**)malloc(100 * sizeof(char*));
    int* path = (int*)malloc(100 * sizeof(int));

    *returnSize = 0;

    dfs(root, path, 0, result1, returnSize);

    return result1;
}