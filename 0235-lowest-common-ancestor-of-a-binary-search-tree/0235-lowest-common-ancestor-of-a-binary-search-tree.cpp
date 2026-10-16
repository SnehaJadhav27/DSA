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
    TreeNode* ans=NULL;
    void fun(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node->val == p->val && node->val == q->val ) {
            ans=node;
            return;
        }

        if(node->val > q->val){
            fun(node->left,p,q);
        } 
        else if(node->val < p->val){
            fun(node->right,p,q);
        } 
        else{
            ans=node;
            return;
        }        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val) fun(root,p,q);
        else  fun(root,q,p);
        return ans;
    }
};