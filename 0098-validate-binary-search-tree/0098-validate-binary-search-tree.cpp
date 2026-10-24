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
public:
    TreeNode* prev=NULL;
    bool ans=true;

    void inorder(TreeNode* node){

        if(node==NULL) return;

        inorder(node->left);

        if(prev!=NULL && node->val<=prev->val){
             ans=false;
        }

        prev=node;

        inorder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};