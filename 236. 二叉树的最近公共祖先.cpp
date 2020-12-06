/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *ans=NULL;
    bool dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return false;
        bool boolleft=dfs(root->left,p,q);
        bool boolright=dfs(root->right,p,q);
        if(boolleft&&boolright||((root->val==p->val||root->val==q->val)&&(boolright||boolleft))){
            ans=root;
        }
        return boolleft||boolright||root->val==p->val||root->val==q->val;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};