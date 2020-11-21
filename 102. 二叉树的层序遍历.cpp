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
    vector<vector<int>> ans;
public:
    void suanfa(TreeNode* root,int n){
        if(ans.size()==n) {
            vector<int> m;
            ans.push_back(m);
        }
        ans[n].push_back(root->val);
        if(root->left) suanfa(root->left,n+1);
        if(root->right) suanfa(root->right,n+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        suanfa(root,0);
        return ans;       
    }
};