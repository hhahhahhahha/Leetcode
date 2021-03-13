class Solution {
public:
    vector<int> ans;
    int suanfa(TreeNode *root, TreeNode* target,int k,bool ks){
        if(root ==NULL) return -1;
        if(ks){
            if(k==0){ans.push_back(root->val);return -1;};
            suanfa(root->left,target,k-1,ks);
            suanfa(root->right,target,k-1,ks);
            return k-1;
        }else if(root==target){
            if(k==0) ans.push_back(root->val);
            suanfa(root->left,target,k-1,true);
            suanfa(root->right,target,k-1,true);
            return k-1;
        }
        int m=suanfa(root->left,target,k,ks); 
        int n=suanfa(root->right,target,k,ks);
        if(m==0||n==0){
            ans.push_back(root->val);
            return -1;
        }
        if(m>0) {
            suanfa(root->right,target,m-1,true);
            return m-1;
        }
        if(n>0){ 
            suanfa(root->left,target,n-1,true);
            return n-1;
        }
        return -1;   
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        suanfa(root,target,K,false);
        return ans;
    }
};