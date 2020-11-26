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
private:
    vector<int> nums;
    bool ans=true;
public:
    void suanfa(TreeNode* root){
        if(root==NULL||ans==false) return;
        suanfa(root->left);
        if(!nums.empty()) ans=ans&&(nums.back()<root->val);
        nums.push_back(root->val);
        suanfa(root->right);
    }
    bool isValidBST(TreeNode* root) {
        suanfa(root);
        return ans; 
    }
};