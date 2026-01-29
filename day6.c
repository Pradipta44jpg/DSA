**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum(struct TreeNode *root, int rootsum, int targetSum){
    if(root==NULL)
    return false;
   
    rootsum=rootsum+root->val;
    if(root->left==NULL && root->right==NULL){
        return (rootsum==targetSum);
    }
    
    return sum(root->left, rootsum,targetSum)|| sum(root->right,rootsum,targetSum);
    

}
bool hasPathSum(struct TreeNode* root, int targetSum) {
     return sum(root,0,targetSum);
    
}