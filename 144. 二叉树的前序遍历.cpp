class Solution {
public:
    vector<int> ans;
    void pre(TreeNode* root){
        if(root==nullptr) return;
        ans.push_back(root->val);
        pre (root->left);
        //ans.push_back(root->val);
        pre (root ->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pre (root);
        return ans;
    }
};