class Solution {
public:
    int ans=0;
    void suanfa(TreeNode* root){
        if(root==nullptr) return;
        ans++;
        suanfa(root->left);
        suanfa(root->right);
    }
    int countNodes(TreeNode* root) {
        suanfa(root);
        return ans;
    }
};