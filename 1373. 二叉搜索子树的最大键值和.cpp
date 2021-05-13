class Solution {
public:
    int ans=0;
    vector<int> suanfa(TreeNode* root){
        vector<int> dp(4,0);
        if(root->left==nullptr&&root->right==nullptr){
            dp[0]=1;
            dp[1]=dp[2]=dp[3]=root->val;
            ans=max(ans,root->val);
        }else if(root->left==nullptr){
            vector<int> rightdp=suanfa(root->right);
            if(rightdp[0]>0&&root->val<rightdp[1]){
                rightdp[1]=root->val;
                rightdp[3]+=root->val;
                ans=max(ans,rightdp[3]);
                return rightdp;
            }
        }else if(root->right==nullptr){
             vector<int> leftdp=suanfa(root->left);
            if(leftdp[0]>0&&root->val>leftdp[2]){
                leftdp[2]=root->val;
                leftdp[3]+=root->val;
                ans=max(ans,leftdp[3]);
                return leftdp;
            }
        }else{
            vector<int> rightdp=suanfa( root->right);
            vector<int> leftdp=suanfa( root->left);
            if((rightdp[0]>0)&&leftdp[0]>0&&root->val<rightdp[1]&&root->val>leftdp[2]){
                leftdp[2]=rightdp[2];
                leftdp[3]+=root->val+rightdp[3];
                ans=max(ans,leftdp[3]);
                return leftdp;
            }
        }
        return dp;
    }
    int maxSumBST(TreeNode* root) {
        suanfa(root);
        return ans;
    }
};