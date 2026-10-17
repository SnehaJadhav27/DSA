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


vector<vector<int>> result;

    void fun(TreeNode* node,int sum, int targetSum,vector<int>diary){
        if(!node) return ;

        sum+=node->val;
        diary.push_back(node->val);

        if(node->left == NULL && node->right == NULL){
            if(sum==targetSum) result.push_back(diary);
            diary.pop_back();
            return; 
        }

        fun(node->left,sum,targetSum,diary);
        fun(node->right,sum,targetSum,diary);
        diary.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        fun(root,0,targetSum,diary);
        return result;
    }
};