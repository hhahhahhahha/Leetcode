class Solution {
public:
    int ans=INT_MIN;
    int suanfa(TreeNode *root){
        if(root==NULL) return 0;
        int left=INT_MIN,right=INT_MIN;
        if(root->left!=NULL) left=suanfa(root->left);
        if(root->right!=NULL) right=suanfa(root->right);
        ans=max(ans,left);
        ans=max(ans,right);
        int returns=0;
        if(left>0) returns+=left;
        if(right>0) returns+=right;
        ans=max(ans,root->val+returns);
        if(root->left==NULL&&root->right==NULL) return root->val; 
        else if(root->right==NULL) return max(root->val+left,root->val);
        else if(root->left==NULL) return max(root->val+right,root->val);
        else return max(root->val+max(left,right),root->val);
    }
    int maxPathSum(TreeNode* root) {
        suanfa(root);
        return ans;
    }
};