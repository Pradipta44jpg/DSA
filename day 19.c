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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    struct TreeNode *queue [10000];
    int rear=0;
    int front=0;
    queue[rear++]=root;
    double* result = (double*)malloc(sizeof(double) * 10000);
    int level=0;
   
    while(front<rear){
        int levelsize=rear-front;
         double sum=0;
        for(int i=0;i<levelsize;i++){
            struct TreeNode* node = queue[front++];
            sum=sum+node->val;
            if(node->left)
            queue[rear++]=node->left;
            if(node->right)
            queue[rear++]=node->right;

        }
        result[level]=sum/levelsize;
        level++;
    }
     *returnSize = level; 
    return result;
}