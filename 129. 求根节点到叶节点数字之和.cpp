class Solution {
public:
    int ans=0;
    void suanfa(int k,TreeNode *root){
        if(root->left==nullptr&&root->right==nullptr) {
            ans+=k*10+root->val;
            return;
        }else{
            k=10*k+root->val;
            if(root->left!=nullptr) suanfa(k,root->left);
            if(root->right!=nullptr) suanfa(k,root->right);
        }
    }
    int sumNumbers(TreeNode* root) {
        suanfa(0,root);
        return ans;
    }
};