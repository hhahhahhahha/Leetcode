class Solution {
public:
    void suanfa(TreeNode *root,vector<TreeNode*>& l){
        if(root==NULL) return;
        l.push_back(root);
        suanfa(root->left,l);
        suanfa(root->right,l);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        suanfa(root,l);
        for(int i=0;i<l.size();i++){
            l[i]->left=nullptr;
            if(i!=l.size()-1) l[i]->right=l[i+1];
        }
    }
};