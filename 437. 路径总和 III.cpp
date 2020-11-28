/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans=0;
public:
    void suanfa(TreeNode* root,int nums,int sum){
        if(root==NULL) return;
        if(nums==INT_MIN){
            suanfa(root->left,INT_MIN,sum);
            suanfa(root->right,INT_MIN,sum);
            if(root->val==sum) ans++;
            suanfa(root->left,root->val,sum);
            suanfa(root->right,root->val,sum);
        }else{
            nums+=root->val;
            if(nums==sum) ans++;
            suanfa(root->left,nums,sum);
            suanfa(root->right,nums,sum);
        } 
    }
    int pathSum(TreeNode* root, int sum) {
        suanfa(root,INT_MIN,sum);
        return ans;
    }
};