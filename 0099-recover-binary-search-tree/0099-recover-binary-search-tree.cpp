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
    TreeNode* g1first=NULL;
    TreeNode* g1second=NULL;
    TreeNode* g2first=NULL;
    TreeNode* g2second=NULL;
    int wrong=0;

    void inorder(TreeNode* node){
        if(node==NULL) return;

        inorder(node->left);

        if(prev!=NULL && node->val < prev->val){
            if(wrong==0){
                g1first=prev;
                g1second=node;
            }
            else{
                g2first=prev;
                g2second=node;
            }
            wrong++;
        }

        prev=node;

        inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(wrong==1){
            swap(g1first->val,g1second->val);
        }
        else{
            swap(g1first->val,g2second->val);
        }

    }
};