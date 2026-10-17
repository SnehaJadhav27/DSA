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
    bool result=false;
    void fun(TreeNode* node,int sum, int targetSum){
        if(!node) return ;

        sum+=node->val;

        if(node->left == NULL && node->right == NULL){
            if(sum==targetSum) result=true;
            return; 
        }

        fun(node->left,sum,targetSum);
        fun(node->right,sum,targetSum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        fun(root,0,targetSum);
        return result;
    }
};